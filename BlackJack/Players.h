#pragma once
#include "GenericPlayer.h"
#include <string>
using namespace std;

class Player : public GenericPlayer
{
public:
	Player(const string& _name = "");
	virtual ~Player();

	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};

class House : public GenericPlayer
{
public:
	House(const string& _name = "House");
	virtual ~House();

	virtual bool IsHitting() const;
	void FlipFirstCard();
};


Player::Player(const string& _name) : GenericPlayer(_name) {};
Player::~Player() {};

bool Player::IsHitting() const {
	cout << mName << ", do you need one more card? (Y/N): ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}

void Player::Win() const {
	cout << mName << " wins!" << endl;
}

void Player::Lose() const {
	cout << mName << " loses!" << endl;
}

void Player::Push() const {
	cout << mName << " pushes!" << endl;
}

House::House(const string& _name) : GenericPlayer(_name) {};
House::~House() {};

bool House::IsHitting() const {
	return (GetTotal() <= 16);
}

void House::FlipFirstCard() {
	if (!mCards.empty()) mCards[0]->Flip();
	return;
}