#include "WebCreator.hpp"

WebCreator::WebCreator(const string& title) {
	m_title = title;
}

WebCreator::~WebCreator() {
	for (int i = 0; i < m_elementList.size(); i++) {
		delete m_elementList[i];
		m_elementList[i] = NULL;
	}
}

void WebCreator::ConvertToHtml(const string& stylePath,
	const string& pagePath, const string& outputPath) {
	ReadStyle(stylePath);
	ReadPage(pagePath);
	BuildPage(outputPath);
}

void WebCreator::ReadStyle(const string& stylePath) {
	string path = stylePath;
	ifstream fin(path);
	while (fin.eof() != true) {
		Style styleitem;
		fin >> styleitem;
		m_styleList.push_back(styleitem);
	}
}

void WebCreator::ReadPage(const string& pagePath) {
	string buffer;
	IElement* ptrIElem = NULL;
	ifstream fin(pagePath);
	while (fin.eof() != true) {
		fin >> buffer;
		if (buffer == "HEADER") {
			ptrIElem = new Header();
			fin >> *ptrIElem;
			m_elementList.push_back(ptrIElem);
		}
		else if (buffer == "PARAGRAPH") {
			ptrIElem = new Paragraph();
			fin >> *ptrIElem;
			m_elementList.push_back(ptrIElem);
		}
		else if (buffer == "LINK") {
			ptrIElem = new Anchor();
			fin >> *ptrIElem;
			m_elementList.push_back(ptrIElem);
		}
		else if (buffer == "TEXTBOX") {
			ptrIElem = new Textbox();
			fin >> *ptrIElem;
			m_elementList.push_back(ptrIElem);
		}
		else if (buffer == "BUTTON") {
			ptrIElem = new Button();
			fin >> *ptrIElem;
			m_elementList.push_back(ptrIElem);
		}
	}
}

void WebCreator::BuildPage(const string& pagePath) {
	ofstream fout(pagePath);
	OutputHeader(fout);
	OutputStyles(fout);
	OutputElements(fout);
	OutputFooter(fout);
}

ostream& WebCreator::OutputHeader(ostream& out) {
	out << "<!DOCTYPE html><html>" << endl
		<< "<head>" << endl
		<< "<title>" << m_title << "</title>" << endl
		<< "</head><body>" << endl;
	return out;
}

ostream& WebCreator::OutputStyles(ostream& out) {
	out << "<style type='text/css'>" << endl;
	int length = m_styleList.size();
	for (int i = 0; i < length; i++) {
		out << m_styleList[i];
	}
	out << "</style>" << endl;
	return out;
}

ostream& WebCreator::OutputElements(ostream& out) {
	int length = m_elementList.size();
	for (int i = 0; i < length; i++) {
		out << *m_elementList[i];
	}
	return out;
}

ostream& WebCreator::OutputFooter(ostream& out) {
	out << endl << "</body></html>" << endl;
	return out;
}