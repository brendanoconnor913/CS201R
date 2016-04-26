#include "Anchor.hpp"

istream& Anchor::Input(istream& in) {
	in >> this->m_href;
	in.ignore();
	getline(in,this->m_text);
	return in;
}

ostream& Anchor::Output(ostream& out) {
	out << "<a href='" << this->m_href;
	out << "'>" << this->m_text << "</a>" << endl;
	return out;
}