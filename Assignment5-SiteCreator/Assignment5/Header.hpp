#ifndef _Header
#define _Header

#include "IElement.hpp"
#include <string>
#include <iostream>
using namespace std;

class Header : public IElement {
public:
	~Header();
	virtual istream& Input(istream& in);
	virtual ostream& Output(ostream& out);
private:
	string m_text;
	int m_headerLevel;
};

#endif
