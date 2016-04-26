#ifndef _Textbox
#define _Textbox

#include "IElement.hpp"
#include <string>
#include <iostream>
using namespace std;

class Textbox : public IElement {
public:
	~Textbox();
	virtual istream& Input(istream& in);
	virtual ostream& Output(ostream& out);
private:
	string m_name;
};

#endif
