#include "Utils.hpp"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Get int input from user inbetween min and max inclusive
int GetUserInput(int minimum, int maximum) {
	bool running = true;
	while (running) {
		int response;
		cout << "Please enter a number: ";
		cin >> response;
		cout << endl;
		// make sure reponse is in range of min and max
		if (response >= minimum && response <= maximum) {
			return response;
		}
		else {
			continue;
		}
	}
}

// get a random int between min and max inclusive
int GetRandom(int minimum, int maximum) {
	int random;
	// make sure rand values in range of min and max
	random = rand() % (maximum - minimum + 1) + minimum;
	return random;
}
