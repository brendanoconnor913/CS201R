#include "User.hpp"
#include <string>
#include <iostream>
using namespace std;


User::User(int startId = 0, const string& firstName = "", const string&
	lastName = "") {
	m_id = startId;
	m_firstName = firstName;
	m_lastName = lastName;
	m_borrowedBookList = NULL;
	m_borrowedCount = 0;
	m_arraySize = 0;
}
User::User(const User& other) {

}
User::~User() {
	if (m_borrowedBookList != NULL) {
		delete[] m_borrowedBookList;
		m_borrowedBookList = NULL;
	}
}
const bool User::HasCheckedOut(const string& bookId) {
	for (int i = 0; i < m_borrowedCount; i++) {
		if (bookId == m_borrowedBookList[i]) {
			return true;
		}
		else {
			return false;
		}
	}
}
const int User::CheckedoutCount() {
	return m_borrowedCount;
}
bool User::CheckOut(const string& bookId) {
	bool checkedout;
	checkedout = HasCheckedOut(bookId);
	if (checkedout) {
		return false;
	}

	if (m_borrowedBookList == NULL) {
		CreateList();
	}

	if (m_borrowedCount == m_arraySize) {
		if (!resizeArray()) {
			return false;
		}
	}

	m_borrowedBookList[m_borrowedCount] = bookId;
	m_borrowedCount++;
}
bool User::CheckIn(const string& bookId) {
	bool checkedout;
	checkedout = HasCheckedOut(bookId);

	if (!checkedout) {
		throw UserExceptionError("Checking in an\
item that has not been checked out!");
	}

	int location;
	for (int i; i < m_borrowedCount; i++) {
		if (bookId == m_borrowedBookList[i]) {
			location = i;
			m_borrowedBookList[i] = m_borrowedBookList[m_borrowedCount - 1];
			m_borrowedBookList[m_borrowedCount - 1] = "";
			m_borrowedCount--;
			if (m_borrowedCount == 0) {
				DestroyList();
			}
		}
	}
	return true;
}

int const User::GetID() {
	return m_id;
}
string const User::GetFirstName() {
	return m_firstName;
}
string const User::GetLastName() {
	return m_lastName;
}
string const User::GetFullName() {
	string full = m_firstName + " " + m_lastName;
	return full;
	
}
void User::SetFirstName(const string& first) {
	m_firstName = first;
}
void User::SetLastName(const string& last) {
	m_lastName = last;
}
void User::SetId(int id) {
	m_id = id;
}

bool const User::operator==(const User& rhs) {

}
User const User::operator+(const User& rhs) {

}
void User::operator+=(const string& rhs) {

}
ostream& operator<<(ostream& out, const User& item) {

}
istream& operator>>(istream& in, User& item) {

}

void User::Clear() {
	m_id = 0;
	m_firstName = "";
	m_lastName = "";
	m_borrowedCount = 0;
	m_arraySize = 0;
	if (m_borrowedBookList != NULL) {
		delete[] m_borrowedBookList;
		m_borrowedBookList = NULL;
	}
}
bool User::resizeArray() {
	try {
		string* tmpArray = new string[m_arraySize * 2];
		for (int i = 0; i < m_arraySize; i++) {
			tmpArray[i] = m_borrowedBookList[i];
		}
		delete[] m_borrowedBookList;
		m_borrowedBookList = tmpArray;
		delete[] tmpArray;
		tmpArray = NULL;
		return true;
	}
	// if you can't allocate memory correctly
	catch (exception) {
		return false;
	}
	
}

void User::CreateList() {
	try {
		m_borrowedBookList = new string[5];
		m_borrowedCount = 0;
		m_arraySize = 5;
	}
	catch (exception) {
		DestroyList();
		throw UserException("Can't get memory.");
	}
}

void User::DestroyList() {
	delete[] m_borrowedBookList;
	m_borrowedBookList = NULL;
	m_arraySize = 0;
	m_borrowedCount = 0;
}