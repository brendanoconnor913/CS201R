#include <string>
using namespace std;

class UserException {
public:
	UserException(const string& message);
	const string What();
private:
	string m_message;
};