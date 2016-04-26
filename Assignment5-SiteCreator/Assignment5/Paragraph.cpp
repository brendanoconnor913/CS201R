#include "Paragraph.hpp"

istream& Paragraph::Input(istream& in) {
	in.ignore();
	getline(in,this->m_text);
	return in;
}

ostream& Paragraph::Output(ostream& out) {
	out << "<p>" << m_text << "</p>" << endl;
	return out;
}