#include "Queue.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// takes in a word and removes any " at the beginning or end of
// the word if it exists, sets rungetline = false if " is at end
// of word
string removeQuotes(string word, bool& rungetline) {
	string newword ="";
	// if at beginning of word
	if (word[0] == '"') {
		for (int i = 1; i < word.size(); i++) {
			newword += word[i];
		}
		return newword;
	}
	// if at end of word
	else if (word[word.size() - 1] == '"') {
		for (int i = 0; i < word.size() - 1; i++) {
			newword += word[i];
		}
		rungetline = false;
		return newword;
	}
	// if not in word
	else {
		return word;
	}
}

int main() {
	// declare variables we will need
	Queue<Team> teamQueue[30];
	vector<Result> resultVec;
	int numinarray = 0;
	ifstream fin("data.csv");
	ofstream foutT("Teams_output.txt");
	ofstream foutR("Ranking_output.txt");
	bool inarray = false;
	bool rungetline = true;
	string line;

	// continue to loop until we reach end of data
	while (fin.eof() != true) {
		Team tmpteam;
		
		// get the data for each line and store in tmpteam vars
		fin >> line;
		tmpteam.time = removeQuotes(line, rungetline);
		fin >> tmpteam.team;
		fin >> tmpteam.problem;
		fin >> line;
		fin >> line;
		tmpteam.solved = removeQuotes(line, rungetline);		

		// check to see if team is already in queue
		for (int i = 0; i < numinarray-1; i++) {
			if (teamQueue[i].front().team == tmpteam.team) {
				teamQueue[i].push(tmpteam);
				inarray = true;
				break;
			}
		}
		// if team isn't in queue
		if (!inarray) {
			// if it is the very first team to go in queue
			if (numinarray == 0) {
				teamQueue[0].pop();
				teamQueue[0].push(tmpteam);
				numinarray++;
				numinarray++;
			}
			// any team after the first to be added to queue
			else {
				teamQueue[numinarray - 1].pop();
				teamQueue[numinarray - 1].push(tmpteam);
				numinarray++;
			}
		}
		// check to see if we should run getline
		// added this because if " is removed at end
		// of line and getline is run it will grab
		// the entire next line of data rather than
		// the end of the current line of data
		if (rungetline) {
			fin.ignore();
			getline(fin, line);
			fin.ignore();
		}
		// resset variables for next loop
		inarray = false;
		rungetline = true;
	}
	// loop for going through data stored in queue and generating
	// results, then storing results in a vector
	for (int i = 0; i < numinarray - 1; i++) {
		int index;
		int problems = 0;
		int time = 0;
		int timebuff = 0;
		int tmp;
		string teamname;
		Team team;
		Result results;

		// start with first team stored in queue
		// and loop until each team finished
		while (!teamQueue[i].empty()) {
			// start with the data entry on team
			team = teamQueue[i].front();
			teamname = team.team;

			// if the problem submission was solved
			if (team.solved == "Yes") {
				problems++;
				tmp = stoi(team.time);
				time += tmp;
				time += timebuff;
				timebuff = 0;
			}
			// if submission was wrong
			else if (team.solved == "No") {
				timebuff += 20;
			}
			// remove current team then loop to next one
			teamQueue[i].pop();
		}
		// store team results in vector
		results.solvdprbs = problems;
		results.teamnum = stoi(teamname);
		results.time = time;
		resultVec.push_back(results);
	}

	// output the team results in order of team number
	int maxprob = 0;
	for (int i = 0; i < numinarray; i++) {
		for (int j = 0; j < resultVec.size(); j++) {
			if (resultVec[j].solvdprbs > maxprob) {
				maxprob = resultVec[j].solvdprbs; // use for output by ranking
			}
			if (resultVec[j].teamnum == i) {
				foutT << "Team " << resultVec[j].teamnum
					<< " solved " << resultVec[j].solvdprbs
					<< " problems in " << resultVec[j].time
					<< " minutes." << endl;
			}
		}
	}

	Queue<vector<Result>> rankQue; // used to store teams by problems solved

	// fill the queue with vectors grouped by number of problems solved by team
	for (maxprob; maxprob >= 0; maxprob--) {
		vector<Result> prblmsVec;
		for (int i = 0; i < resultVec.size(); i++) {
			if (resultVec[i].solvdprbs == maxprob) {
				prblmsVec.push_back(resultVec[i]);
			}
		}
		rankQue.push(prblmsVec);
	}

	// output results descending from most problems solved and
	// lowest time to least problems solved and highest time
	while (!rankQue.empty()) {
		vector<Result> prblms = rankQue.front();
		// loop through each team with same number
		// of problems solved
		while (!prblms.empty()) {
			int min = 1000000;
			// find the team with min ammount of total time
			for (int i = 0; i < prblms.size(); i++) {
				if (prblms[i].time < min) {
					min = prblms[i].time;
				}
			}
			// output team with min time then remove from vector
			for (int i = 0; i < prblms.size(); i++) {
				if (prblms[i].time == min) {
					foutR << "Team " << prblms[i].teamnum
						<< " solved " << prblms[i].solvdprbs
						<< " problems in " << prblms[i].time
						<< " minutes." << endl;
					prblms.erase(prblms.begin() + i);
					break;
				}
			}
			// repeat outputting min for each num of problems solved
			// until all teams with that number of problems solved is
			// exhausted then move to team with one less problem solved
			// continue until all teams outputted
		}
		rankQue.pop();
	}

	// close i/o files
	fin.close();
	foutR.close();
	foutT.close();
	return 0;
}