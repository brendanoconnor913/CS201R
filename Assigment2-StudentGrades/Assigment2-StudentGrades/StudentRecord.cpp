#include "StudentRecord.hpp"

StudentRecord::StudentRecord() {
	for (int i = 0; i < 4; i++) {
		StudentRecord::exams[i].score = 0;
		StudentRecord::exams[i].weight = 0;
	}
}

void StudentRecord::SetStudentId(int id) {
	StudentRecord::m_studentId = id;
}

int StudentRecord::GetStudentId() {
	return StudentRecord::m_studentId;
}

void StudentRecord::AddExam(int index, float score, float weight) {
	StudentRecord::exams[index].score = score;
	StudentRecord::exams[index].weight = weight;
}

void StudentRecord::GetFinalGrade(float& numeric, char& letter) {

	for (int i = 0; i < 4; i++) {
		numeric += StudentRecord::exams[i].score * \
			StudentRecord::exams[i].weight;
	}
	if (numeric >= 90) {
		letter = 'A';
	}
	else if (numeric >= 80) {
		letter = 'B';
	}
	else if (numeric >= 70) {
		letter = 'C';
	}
	else {
		letter = 'D';
	}
}