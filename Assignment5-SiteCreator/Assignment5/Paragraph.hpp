#ifndef _Paragraph
#define _Paragraph

#include "IElement.hpp"
#include <string>
#include <iostream>
using namespace std;

class Paragraph : public IElement {
public:
	~Paragraph();
	virtual istream& Input(istream& in);
	virtual ostream& Output(ostream& out);
private:
	string m_text;
};

#endif
