#include "User.hpp"
#include "UserException.hpp"
#include <string>
#include <iostream>
using namespace std;

// Constructor for normal user object
User::User(int startId, const string& firstName, const string&
	lastName) {
	m_id = startId;
	m_firstName = firstName;
	m_lastName = lastName;
	m_borrowedBookList = NULL;
	m_borrowedCount = 0;
	m_arraySize = 0;
}

// Constructor for copying other user objects
User::User(const User& other) {
	*this = other;
}

User::~User() {
	if (m_borrowedBookList != NULL) {
		delete[] m_borrowedBookList;
		m_borrowedBookList = NULL;
	}
}

// determine whether User has checkedout book
const bool User::HasCheckedOut(const string& bookId) {
	for (int i = 0; i < m_borrowedCount; i++) {
		if (bookId == m_borrowedBookList[i]) {
			return true;
		}
	}
	return false;
}

// How many books user has checked out
const int User::CheckedoutCount() {
	return m_borrowedCount;
}

// Checkout out book to User
bool User::CheckOut(const string& bookId) {
	bool checkedout;
	string book = bookId;
	checkedout = HasCheckedOut(bookId);
	if (checkedout) {
		return false;
	}

	if (m_borrowedBookList == NULL) {
		CreateList();
	}

	if (m_borrowedCount == m_arraySize) {
		bool resize = resizeArray();
		if (!resize) {
			return false;
		}
	}

	m_borrowedBookList[m_borrowedCount] = book;
	m_borrowedCount++;
}

// Check in book to User
bool User::CheckIn(const string& bookId) {
	bool checkedout;
	checkedout = HasCheckedOut(bookId);

	if (!checkedout) {
		UserException e("Checking in an item that has not been checked out!");
		throw e;
	}

	for (int i = 0; i < m_borrowedCount; i++) {
		if (bookId == m_borrowedBookList[i]) {
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

// Check equality of User objects
bool const User::operator==(const User& rhs) {
	User tmprhs;
	tmprhs = rhs;
	if (this->GetFullName() == tmprhs.GetFullName()) {
		return true;
	}
	else {
		return false;
	}
}

// return result of Adding a book to a user's checkedout list
const User User::operator+(const string& newItem) {
	User result;
	result = *this;
	result.CheckOut(newItem);
	return result;	
}

// add book to User's checked out list
void User::operator+=(const string& rhs) {
	this->CheckOut(rhs);
}

// Output information on User and their checkouts
ostream& operator<<(ostream& out, const User& item) {
	User usr(item);
	out << "USER " << usr.m_id << endl;
	out << "\t " << "NAME " << usr.GetFullName() << endl;
	out << "\t " << "BOOK_COUNT " << usr.m_borrowedCount << endl;
	for (int i = 0; i < usr.m_borrowedCount; i++) {
		out << "\t\t " << usr.m_borrowedBookList[i] << endl;
	}
	out << "END" << endl;
	out << endl;
	return out;
}

// Input info needed for User and their checkouts
istream& operator>>(istream& in, User& item) {
	string ignr;
	int bookcount;
	string bookname;

	in >> ignr >> item.m_id;
	in >> ignr >> item.m_firstName >> item.m_lastName;
	in >> ignr >> bookcount;

	for (int i = 0; i < bookcount; i++) {
		in >> bookname;
		try {
			item += bookname;
		}
		catch (UserException e) {
			cerr << "Error checking the book " << bookname << ": " << e.What() << endl;
		}
	}
	in >> ignr;
	return in;
}

// Clear a User contact
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

// Make checkouts array larger
bool User::resizeArray() {
	try {
		string* tmpArray = new string[m_arraySize * 2];
		for (int i = 0; i < m_arraySize; i++) {
			tmpArray[i] = m_borrowedBookList[i];
		}
		delete[] m_borrowedBookList;
		m_borrowedBookList = tmpArray;
		tmpArray = NULL;
		m_arraySize = m_arraySize * 2;
		return true;
	}
	// if you can't allocate memory correctly
	catch (exception) {
		return false;
	}
	
}

// Create an array to store book checkouts
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

// Destory the book checkout array
void User::DestroyList() {
	delete[] m_borrowedBookList;
	m_borrowedBookList = NULL;
	m_arraySize = 0;
	m_borrowedCount = 0;
}