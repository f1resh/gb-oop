#pragma once
#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "Players.h"
using namespace std;

int main()
{
	Card *first = new Card(Suit::Clubs, Rank::Ace);
	Card *second = new Card(Suit::Spades, Rank::Queen);
	Card *third = new Card(Suit::Hearts, Rank::King, true);
	Card *fourth = new Card(Suit::Diamonds, Rank::Seven);
	first->Flip();
	second->Flip();
	fourth->Flip();
	cout << "First card is " << *first << endl;
	cout << "Second card is " << *second << " points :" << second->GetValue() << endl;
	cout << "Third card is " << *third << endl;
	cout << "Fourth card is " << *fourth << endl;

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
	//myHand.Clear();
	cout << "Clearing of hand. First card does not exist. Value = " << first->GetValue() << endl;
	cout << "Total points in Hand = " << myHand.GetTotal() << endl;

	Player *player1 = new Player("Pavel");
	House *Dealer = new House();

	player1->Add(fourth);
	player1->Add(third);
	//player1->Add(second);
	player1->Add(first);
	cout << *player1;


	return 0;
}


