#ifndef _WebCreator
#define _WebCreator

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "IElement.hpp"
#include "Style.hpp"
#include "Button.hpp"
#include "Anchor.hpp"
#include "Header.hpp"
#include "Paragraph.hpp"
#include "Textbox.hpp"
using namespace std;

class WebCreator {
public:
	WebCreator(const string& title);
	~WebCreator();
	void ConvertToHtml(const string& stylePath, const string& pagePath,
		const string& outputPath);
private:
	vector<Style> m_styleList;
	vector<IElement*> m_elementList;
	string m_title;

	void ReadStyle(const string& stylePath);
	void ReadPage(const string& pagePath);
	void BuildPage(const string& pagePath);

	ostream& OutputHeader(ostream& out);
	ostream& OutputStyles(ostream& out);
	ostream& OutputElements(ostream& out);
	ostream& OutputFooter(ostream& out);
};

#endif