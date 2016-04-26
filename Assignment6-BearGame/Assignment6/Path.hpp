#ifndef _PATH
#define _PATH

#include<iostream>
#include<vector>
using namespace std;

class Path {
public:
	Path(int startNum);
	void rule1(); 
	void rule2(); 
	void rule3();
	void solution();
	int length();
	int getCurrentNum() { return currentNum; }
	const bool operator<(const Path& rhs);
	friend ostream& operator<<(ostream& out, const Path& path);

private:
	vector<int> rules;
	vector<int> numHistory;
	int currentNum;
};

#endif