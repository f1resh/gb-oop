#pragma once
#include "Hand.h"
#include "GenericPlayer.h"
#include <random>
#include <algorithm>

class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();
	void Populate();
	void Shuffle();
	void Deal(Hand& hand);
	void AdditionalCards(GenericPlayer& genericPlayer);
};

Deck::Deck() {
	mCards.reserve(52);
	Populate();
}

Deck::~Deck(){}

void Deck::Populate() {
	for (int suit = (int)Suit::Hearts; suit <= (int)Suit::Clubs; ++suit) {
		for (int rank = (int)Rank::Two; rank <= (int)Rank::King; ++rank) {
			Add(new Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
		}
	}
}

void Deck::Shuffle() {
	auto rd = std::random_device{};
	auto rng = std::default_random_engine{ rd() };
	std::shuffle(std::begin(mCards), std::end(mCards), rng);
}

void Deck::Deal(Hand& hand)
{
	if (!mCards.empty()) {
		hand.Add(this->mCards.back());
		this->mCards.pop_back();
	}
	else {
		std::cout << "Deck is empty!" << std::endl;
	}
}

void Deck::AdditionalCards(GenericPlayer& genericPlayer)
{
	while (!genericPlayer.IsBusted() && genericPlayer.IsHitting()) {
		Deal(genericPlayer);
		std::cout << genericPlayer << std::endl;

		if (genericPlayer.IsBusted()) genericPlayer.Bust();
	}
}
