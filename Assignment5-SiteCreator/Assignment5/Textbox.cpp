#include "Textbox.hpp"

istream& Textbox::Input(istream& in) {
	in >> this->m_name;

	return in;
}

ostream& Textbox::Output(ostream& out) {
	out << "<input type='text' name='" << m_name << "'>" << endl;
	return out;
}