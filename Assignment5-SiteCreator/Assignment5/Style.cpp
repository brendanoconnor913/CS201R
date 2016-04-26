#include "Style.hpp"
#include <iostream>
#include <string>

istream& operator>>(istream& in, Style& item) {
	in >> item.element >> item.attribute >> item.value;

	return in;
}

ostream& operator<<(ostream& out, const Style& item) {
	out << item.element << " { " << item.attribute << ": ";
	out << item.value << "; }" << endl;
	return out;
}