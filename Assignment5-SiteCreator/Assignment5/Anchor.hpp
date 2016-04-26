#ifndef _Anchor
#define _Anchor

#include "IElement.hpp"
#include <string>
#include <iostream>
using namespace std;

class Anchor : public IElement {
public:
	~Anchor();
	virtual istream& Input(istream& in);
	virtual ostream& Output(ostream& out);
private:
	string m_href;
	string m_text;
};

#endif