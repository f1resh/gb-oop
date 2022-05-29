#include <iostream>
#include "Card.h"
using namespace std;

int main()
{
	Card first(Suit::Clubs, Rank::Ace);
	Card second(Suit::Spades, Rank::Queen);
	Card third(Suit::Hearts, Rank::King, true);
	Card fourth(Suit::Diamonds, Rank::Seven);
	cout << "First card is Ace of Clubs. Value = " << first.GetValue() << endl;
	cout << "Second card is Queen of Spades. Value = " << second.GetValue() << endl;
	cout << "Third card is King of Hearts. Value = " << third.GetValue() << endl;
	cout << "Fourth card is Sevend of Diamonds. Value = " << fourth.GetValue() << endl;
	return 0;
}


