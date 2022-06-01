#pragma once
#include <vector>
#include "Card.h"
#define MAX_POINTS 21
using namespace std;

class Hand {
private:
	vector<Card*> mCards;
public:
	Hand();
	virtual ~Hand();
	void Add(Card *pCard) {
		if (pCard == nullptr) return;
		mCards.push_back(pCard);
	}
	void Clear() {
		for (auto card : mCards) {
			delete card;
			card = 0;
		}
		mCards.clear();
	};
	void DropHand() {
		mCards.clear();
	}
	int GetTotal() const;
};

Hand::Hand() {
	mCards.reserve(7);
}

Hand::~Hand() {
	Clear();
}

int Hand::GetTotal() const {
	if (mCards.empty()) return 0; // No cards in hand
	if (mCards[0]->GetValue() == 0) return 0; // First card is face down
	int total = 0;
	int aceNumber = 0;

	for (const auto card : mCards) {
		total += card->GetValue();
		if (card->rank == Rank::Ace) aceNumber++;
	}

	while (total > MAX_POINTS && aceNumber > 0) {
		total -= 10;
		--aceNumber;
	}

	return total;

}
