#include <string>
#include <iostream>
#include "Path.hpp"
using namespace std;

// check to see if number is a multiple of 3
bool isMult3(int num) {
	if (num % 3 == 0) {
		return true;
	}
	else {
		return false;
	}
}

// check to see if number is even
bool isEven(int num) {
	if (num % 2 == 0) {
		return true;
	}
	else {
		return false;
	}
}

// apply the given 3 rules to see if we can find a path
// to having exactly 17 bears
Path transverse(Path path) {
	if (path.length() <= 20) { // make sure we don't go over 20 steps
		int currentn = path.getCurrentNum();
		if (currentn == 17) { // if we reach 17 we know we have a solution
			path.solution();
			return path;
		}
		else { 
			if (currentn < 17) { // if number is less than our goal we will want to add to it
				if (isMult3(currentn)) {
					path.rule2();
					return transverse(path);
				}
				else {
					path.rule3();
					return transverse(path);
				}
			}
			else if (currentn > 17) { 
				// if number is greater than our goal we want to reduce it
				// if we can't reduce it try to add as little as possible
				// (rule 2 before rule 3)
				if (isEven(currentn)) {
					path.rule1();
					return transverse(path);
				}
				else {
					if (isMult3(currentn)) {
						path.rule2();
						return transverse(path);
					}
					else {
						path.rule3();
						return transverse(path);
					}
				}
			}
		}
	}
	else { 
		// If we don't find a solution return 
		// a path with a current number of -1
		Path deadbranch(-1);
		return deadbranch;
	}
}

int main() {
	int startNum;
	string response;
	bool running = true;
	while (running) { // loop until user is done
		cout << "How many bears would you like to start with? ";
		cin >> startNum;
		while (startNum < 0 || startNum > 10000) { // verify input
			cout << "Please enter a number between 0 and 10,000 you wish to start with: ";
			cin >> startNum;
		}

		Path tree(startNum);
		tree = transverse(tree); // try and find a solution
		if (tree.getCurrentNum() == -1) {
			cout << "No solution found within 20 moves..." << endl;
		}
		else {
			cout << tree; // output solution
		}

		cout << endl << "Would you like to try again[Y/N]? ";
		cin >> response;
		if (response == "Y" || response == "y") {
			running = true;
		}
		else {
			running = false;
		}
	}
	return 0;
}