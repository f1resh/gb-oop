#pragma once
#include <string>

class Ex {
private:
	double x;
public:
	Ex(double _x) : x(_x) {};
	const std::string what(){
		return "Exception with value " + std::to_string(x);
	}

};

class Bar {
private:
	double y;
public:
	Bar(double _y = 0) : y(_y) {};
	void set(double a) {
		if (y + a > 100) throw Ex(y * a);
		y = a;
	}
};
