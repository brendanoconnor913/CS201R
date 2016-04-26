#include "IElement.hpp"
#include <iostream>
#include <string>
using namespace std;

istream& operator>>(istream& in, IElement& item) {
	return item.Input(in);
}

ostream& operator<<(ostream& out, IElement& item) {
	return item.Output(out);
}

