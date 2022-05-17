#pragma once
#include <iostream>
using namespace std;


class Power
{
private:
	float base = 10;
	int n = 1;

	void Print(float _num) {
		cout << base << "^" << n << " = " << _num << endl;
	}

public:
	Power() = default;

	void Set(float _base, int _n){
		base = _base;
		n = _n;
	}

	float Calculate(){
		float p = 1;
		if (n < 0) {
			for (int i = 0; i < -n; i++) {
				p /= base;
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				p *= base;
			}
		}
		Print(p);
		return p;
	}

	
};

