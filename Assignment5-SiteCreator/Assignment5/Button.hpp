#ifndef _Button
#define _Button

#include "IElement.hpp"
#include <string>
#include <iostream>
using namespace std;

class Button : public IElement {
public:
	~Button();
	virtual istream& Input(istream& in);
	virtual ostream& Output(ostream& out);
private:
	string m_name;
	string m_value;
};

#endif

