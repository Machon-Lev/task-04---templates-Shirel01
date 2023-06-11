#pragma once

#include <iostream>
#include <list>
#include <exception>

template <class T>
struct MyComparator
{
	T operator()(const T& a, const T& b) {
		return a - b;
	}
};

template <typename T>
class PriorityQueue {

private:
    std::list<T> data;  

public:
 
	void push(const T& t);
	T poll();


};


template<typename T>
inline void PriorityQueue<T>::push(const T& t)
{
	MyComparator<T> comp;
	typename std::list<T>::iterator it;

	for (it = data.begin(); it != data.end(); ++it) {
		
		if (comp(t,*it)<0){   //t< *it  
			break;
		}
	}
	data.insert(it, t);
}

template<typename T>
inline T PriorityQueue<T>::poll()
{
	if (data.empty())
		throw std::exception("Priority queue empty ! ");

	T i = data.front();
	data.pop_front();  
	return i;
}
