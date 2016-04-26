#include "User.hpp"
#include "UserException.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	// Open files for input/output
	ifstream users;
	ifstream checkouts;
	ifstream checkins;
	ofstream usersout;
	ofstream dupsout;

	users.open("users.txt");
	checkouts.open("checkouts.txt");
	checkins.open("checkins.txt");
	usersout.open("output_users.txt");
	dupsout.open("output_dupes.txt");


	int usercount;
	string ignore;
	users >> ignore >> usercount;

	// Initalize userArray to size of number of users
	User *userArray = new User[usercount];

	// Store each entry in users.txt into users objects
	for (int i = 0; i < usercount; i++) {
		users >> userArray[i];
	}

	// output each duplicate to dupsout
	int dupcount = 0;
	dupsout << "DUPLICATES" << endl;
	for (int i = 0; i < usercount; i++) {
		for (int j = i; j < usercount; j++) {
			if (userArray[i].GetFullName() == userArray[j].GetFullName()) {
				if (userArray[i].GetID() != userArray[j].GetID()) {
					dupsout << "User " << userArray[i].GetLastName();
					dupsout << ", " << userArray[i].GetFirstName();
					dupsout << " duplicates at " << userArray[i].GetID();
					dupsout << " and " << userArray[j].GetID() << endl;
					dupcount++;
				}
			}
		}
	}
	dupsout << endl;
	dupsout << dupcount << " total duplicates";

	// Read through checkouts and checkout book to person's ID
	checkouts >> ignore >> ignore;
	int id;
	string book;
	while (checkouts.eof() != true) {
		checkouts >> id >> book;
		for (int i = 0; i < usercount; i++) {
			if (id == userArray[i].GetID()) {
				try {
					userArray[i] += book;
				}
				catch (UserException e) {
					cerr << "Error checking out " << book << ": " << e.What() << endl;
				}
			}
		}
	}

	// Checkin books to the people who checked them out
	checkins >> ignore;
	while (checkins.eof() != true) {
		checkins >> book;
		for (int i = 0; i < usercount; i++) {
			if (userArray[i].HasCheckedOut(book)) {
				try {
					userArray[i].CheckIn(book);
				}
				catch (UserException e) {
					cerr << "Error checking out " << book << ": " << e.What() << endl;
				}
			}
		}
	}

	// Output the current users with their checked out books
	usersout << "USER_COUNT " << usercount << endl;
	usersout << endl;
	for (int i = 0; i < usercount; i++) {
		usersout << userArray[i];
	}

	// Close files
	users.close();
	checkouts.close();
	checkins.close();
	usersout.close();
	dupsout.close();
	return 0;
}