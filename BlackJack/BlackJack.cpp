#include <iostream>
#include "Card.h"
#include "Hand.h"
using namespace std;

int main()
{
	Card *first = new Card(Suit::Clubs, Rank::Ace);
	Card *second = new Card(Suit::Spades, Rank::Queen);
	Card *third = new Card(Suit::Hearts, Rank::King, true);
	Card *fourth = new Card(Suit::Diamonds, Rank::Seven);
	cout << "First card is Ace of Clubs. Value = " <<first->GetValue() << endl;
	cout << "Second card is Queen of Spades. Value = " << second->GetValue() << endl;
	cout << "Third card is King of Hearts. Value = " << third->GetValue() << endl;
	cout << "Fourth card is Sevend of Diamonds. Value = " << fourth->GetValue() << endl;

	Hand myHand;
	myHand.Add(first);
	myHand.Add(second);
	myHand.Add(third);
	myHand.Add(fourth);
	cout << "Total points in Hand = " << myHand.GetTotal() << endl;

	myHand.DropHand();
	cout << "Dropping of hand. First card still exists. Value = " << first->GetValue() << endl;
	cout << "Total points in Hand = " << myHand.GetTotal() << endl;


	myHand.Add(first);
	myHand.Clear();
	cout << "Clearing of hand. First card does not exist. Value = " << first->GetValue() << endl;
	cout << "Total points in Hand = " << myHand.GetTotal() << endl;


	return 0;
}


