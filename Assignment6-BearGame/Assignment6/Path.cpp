#include "Path.hpp"
#include <iostream>
#include <string>
using namespace std;


Path::Path(int startNum) {
	currentNum = startNum;
}

// if even half currentNum
void Path::rule1() {
	rules.push_back(1);
	numHistory.push_back(currentNum);
	currentNum = currentNum / 2;
}

// if multiple of 3 add 1/3 to currentNum
void Path::rule2() {
	rules.push_back(2);
	numHistory.push_back(currentNum);
	currentNum = currentNum + (currentNum/3);
}

// Add 23
void Path::rule3() {
	rules.push_back(3);
	numHistory.push_back(currentNum);
	currentNum += 23;
}

// the currentNum reached 17 and a solution branch was found
void Path::solution() {
	numHistory.push_back(currentNum);
}

// get the length of the path
int Path::length() {
	return numHistory.size();
}

// compare the length of one path to another
const bool Path::operator<(const Path& rhs) {
	Path tmprhs = rhs;
	if (this->length() < tmprhs.length()) {
		return true;
	}
	else {
		return false;
	}
}

// output a path object by outputting each rule applied with the
// corresponding reslut to the number
ostream& operator<<(ostream& out, const Path& path) {
	Path tmppath = path;
	int rule;
	int number;

	out << "Solution found!" << endl;
	out << "I have exactly 17 bears with " << 20 - tmppath.length()+1
		<< " moves left." << endl;

	// Go through each stored number and output the rule applied to it
	for (int i = 0; i < tmppath.length() - 1; i++) {
		rule = tmppath.rules[i];
		switch (rule) {
		case 1:
			out << "Reduce " << tmppath.numHistory[i]
				<< " by half to get " << tmppath.numHistory[i + 1] << "."
				<< endl;
			break;
		case 2:
			out << "With " << path.numHistory[i]
				<< " add 1/3 to get " << tmppath.numHistory[i + 1] << "."
				<< endl;
			break;
		case 3:
			out << "With " << path.numHistory[i]
				<< " add 23 to get " << tmppath.numHistory[i + 1] << "."
				<< endl;
			break;
			
		}
	}
		
	return out;
}