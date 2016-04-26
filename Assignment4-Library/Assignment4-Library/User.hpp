#ifndef _User
#define _User

#include <string>

using namespace std;

class User {
public:
	User(int startId = 0, const string& firstName = "", const string&
		lastName = "");
	User(const User& other);
	~User();
	const bool HasCheckedOut(const string& bookId);
	const int CheckedoutCount();
	bool CheckOut(const string& bookId);
	bool CheckIn(const string& bookId);

	int const GetID();
	const string GetFirstName();
	const string GetLastName();
	const string GetFullName();
	void SetFirstName(const string& first);
	void SetLastName(const string& last);
	void SetId(int id);

	void CreateList();
	void DestroyList();

	const bool operator==(const User& rhs);
	const User operator+(const string& newItem);
	void operator+=(const string& rhs);
	friend ostream& operator<<(ostream& out, const User& item);
	friend istream& operator>>(istream& in, User& item);

	void Clear();
private:
	unsigned int m_id;
	string m_firstName;
	string m_lastName;
	string* m_borrowedBookList;
	unsigned int m_borrowedCount;
	unsigned int m_arraySize;

	bool resizeArray();
};

#endif
