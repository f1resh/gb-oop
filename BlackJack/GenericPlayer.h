#pragma once
#include <string>
#include "Hand.h"
#include <iostream>
#include <string>
#define MAX_POINTS 21
using namespace std;

class GenericPlayer : public Hand
{
private:
	friend ostream& operator<<(ostream& out, const GenericPlayer& GenericPlayer);
protected: 
	string mName;
public:
	GenericPlayer(const string& _name ="");
	virtual ~GenericPlayer();
	virtual bool IsHitting() const = 0;
	bool IsBusted() const {
		return GetTotal() > MAX_POINTS;
	}
	void Bust() const {
		cout << mName << " has busted! Total number of points = " << GetTotal() << endl;
	}

};

ostream& operator<<(ostream& out, const GenericPlayer& GenericPlayer) {
	out << GenericPlayer.mName << ":\t";
	if (!GenericPlayer.mCards.empty()) {
		for (const auto card : GenericPlayer.mCards) {
			out << *card << "\t";
		}
		if (GenericPlayer.GetTotal() > 0) {
			out << "(" << GenericPlayer.GetTotal() << " points)";
		}
	}
	else {
		out << "<empty>";
	}
	return out;
};

GenericPlayer::GenericPlayer(const string& _name) : mName(_name) {};
GenericPlayer::~GenericPlayer() {};