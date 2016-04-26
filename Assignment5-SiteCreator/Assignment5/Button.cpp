#include "Button.hpp"

istream& Button::Input(istream& in) {
	in >> this->m_name;
	in.ignore();
	getline(in, this->m_value);
	return in;
}

ostream& Button::Output(ostream& out) {
	out << "<input type='button' name='" << this->m_name;
	out << "' value='" << this->m_value << "'>" << endl;
	return out;
}