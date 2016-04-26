#include "Header.hpp"

istream& Header::Input(istream& in) {
	string size;
	in >> size;
	if (size == "size_small") {
		this->m_headerLevel = 3;
	}
	else if (size == "size_medium") {
		this->m_headerLevel = 2;
	}
	else if (size == "size_big") {
		this->m_headerLevel = 1;
	}
	in.ignore();
	getline(in, this->m_text);
	return in;
}

ostream& Header::Output(ostream& out) {
	switch (this->m_headerLevel) {
	case 3:
		out << "<h3>" << this->m_text << "</h3>" << endl;
		break;
	case 2:
		out << "<h2>" << this->m_text << "</h2>" << endl;
		break;
	case 1:
		out << "<h1>" << this->m_text << "</h1>" << endl;
		break;
	}
	return out;
}