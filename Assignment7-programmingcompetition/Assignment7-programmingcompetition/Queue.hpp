#ifndef __QUEUE
#define __QUEUE

#include <list>
#include <string>
using namespace std;

struct Team {
	string time = "";
	string team = "";
	string problem = "";
	string solved = "";
};

struct Result {
	int time;
	int solvdprbs;
	int teamnum;
};

template<class T>
class Queue {
public:
	Queue<T>();
	void push(T obj);
	void pop();
	T front();
	int size();
	bool empty();
	
private:
	list<T> m_list;
};

template<class T>
Queue<T>::Queue() {
	T init;
	m_list.push_back(init);
}

template<class T>
void Queue<T>::push(T obj) {
	m_list.push_back(obj);
}

template<class T>
void Queue<T>::pop() {
	m_list.pop_front();
}

template<class T>
T Queue<T>::front() {
	return m_list.front();
}

template<class T>
int Queue<T>::size() {
	return m_list.size();
}

template<class T>
bool Queue<T>::empty() {
	return m_list.empty();
}

#endif