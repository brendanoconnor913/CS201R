#ifndef _Style
#define _Style

#include <string>
#include <iostream>
using namespace std;

struct Style {
	string element;
	string attribute;
	string value;
	
	friend ostream& operator<<(ostream& out, const Style& item);
	friend istream& operator>>(istream& in, Style& item);
};

#endif