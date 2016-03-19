#include <iostream>
#include <string>
#include <fstream>

#include "StudentRecord.hpp"
using namespace std;


int main() {
	ifstream fin("grade1.txt");
	ofstream fout("output.txt");
	//StudentId, assignment score, exam 1, exam 2, final exam

	
	StudentRecord students[14];
	for (int i = 0; i < 14; i++) {
		// Initalize variables and fill w/ data from first line
		int id, e1, e2, e3, e4;
		fin >> id >> e1 >> e2 >> e3 >> e4;

		students[i].SetStudentId(id);
		students[i].AddExam(0, e1, .20);
		students[i].AddExam(1, e2, .25);
		students[i].AddExam(2, e3, .25);
		students[i].AddExam(3, e4, .30);
	}
	fin.close();
	// all data from file inputted, close input and open output

	for (int i = 0; i < 14; i++) {
		float numeric = 0;
		char letter = 'n';
		int id;

		id = students[i].GetStudentId();
		students[i].GetFinalGrade(numeric, letter);

		fout << id << "\t" << "After final " << numeric << " %\t" \
			<< "Overall Grade is " << letter << endl;
	
	}

	fout.close();
	return 0;
}