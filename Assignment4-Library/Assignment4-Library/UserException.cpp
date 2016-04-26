#include "UserException.hpp"
#include <string>
using namespace std;

UserException::UserException(const string& message) {
	m_message = message;
}

const string UserException::What() {
	return m_message;
}