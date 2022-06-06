#pragma once
#include <iostream>

enum class Suit {
    Hearts,
    Diamonds,
    Spades,
    Clubs
};

enum class Rank {
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Ace = 11,
    Jack,
    Queen,
    King,
    
};

class Card {
private:
    Suit suit;
    Rank rank;
    bool face;
    Card() = default;
    friend std::ostream& operator<<(std::ostream& out, const Card&);
public:
    Card(Suit _suit, Rank _rank, bool _face = false) : suit(_suit), rank(_rank), face(_face) {};
    void Flip(){
        face = !face;
    };
    bool isFaceUp() const {
        return face;
    }
    int GetValue() const {
        if (!face) return 0;
        if ((int)rank > 11) return 10;
        return (int)rank;
    }
    friend class Hand;

};


std::ostream& operator<< (std::ostream & out, const Card & card) {
    const std::string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8","9","10", "A", "J", "Q", "K"};
    const std::string SUITS[] = { "H", "D", "S", "C" };
    if (card.isFaceUp()) {
        int rIndex;
        switch (card.rank) {
        case (Rank::Jack):
                rIndex = 12;
                break;
        case (Rank::Queen):
                rIndex = 13;
                break;
        case (Rank::King):
                rIndex = 14;
                break;
        default:
                rIndex = (int)card.rank;
                break;
        }
        out << RANKS[rIndex] << SUITS[(int)card.suit];
    }
    else {
        out << "XX";
    }
    return out;
}