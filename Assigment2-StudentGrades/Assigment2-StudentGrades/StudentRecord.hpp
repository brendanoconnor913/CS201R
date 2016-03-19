#ifndef _StudentRecord
#define _StudentRecord

#include "Exam.h"

class StudentRecord {
public:
	StudentRecord();
	void SetStudentId(int id);
	int GetStudentId();
	void AddExam(int index, float score, float weight);
	void GetFinalGrade(float& numeric, char& letter);

private:
	int m_studentId;
	Exam exams[4];
};

#endif