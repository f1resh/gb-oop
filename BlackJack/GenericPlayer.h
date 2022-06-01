#pragma once
#include <string>
#include "Hand.h"
#include <iostream>
#define MAX_POINTS 21
using namespace std;

class GenericPlayer : public Hand
{
private:
	string mName;
public:
	virtual bool IsHitting() const = 0;
	bool IsBusted() const {
		if (GetTotal() > MAX_POINTS) return true;
		return false;
	}
	void Bust() const {
		cout << mName << " has busted! Total number of points = " << GetTotal() << endl;
	}

};

