#pragma once
#include <string>
using namespace std;

template<class T>
class Pair1
{
private:
	T one;
	T two;
public:
	Pair1(T _one, T _two) : one(_one), two(_two) {};
	~Pair1() {};
	T first() const {
		return one;
	}
	T second() const {
		return two;
	}
};


template<class T1, class T2>
class Pair {
private:
	T1 one;
	T2 two;
public:
	Pair(T1 _one, T2 _two) : one(_one), two(_two) {};
	~Pair() {};
	T1 first() const {
		return one;
	}
	T2 second() const {
		return two;
	}

};


template<class T>
class StringValuePair : public Pair<string, T> {
public:
	StringValuePair<T>(string _one, T _two) : Pair<string,T>(_one,_two) {}
	~StringValuePair<T>() {}
};