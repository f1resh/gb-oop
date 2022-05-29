#pragma once
#include <vector>
#include "Card.h"
using namespace std;

class Hand {
private:
	vector<Card*> mCards;
public:
	void Add(Card *pCard) {
		if (pCard == nullptr) return;
		mCards.push_back(pCard);
	}
	void Clear() {
		for (auto card : mCards) {
			delete card;
		}
		mCards.clear();
	};
	void DropHand() {
		mCards.clear();
	}
	int GetTotal() {
		int total = 0;
		int aceNumber = 0;
		
		for (const auto card : mCards) {
			total += card->GetValue();
			if (card->rank == Rank::Ace) aceNumber++;
		}

		while (total > 21 && aceNumber > 0) {
			total -= 10;
			--aceNumber;
		}

		return total;

	}
};
