#pragma once

enum class Suit{
    Hearts,
    Diamonds,
    Spades,
    Clubs
};

enum class Rank{
    Two     =   2,
    Three   =   3,
    Four    =   4,
    Five    =   5,
    Six     =   6,
    Seven   =   7,
    Eight   =   8,
    Nine    =   9,
    Ten     =   10,    
    Jack    =   10,
    Queen   =   10,
    King    =   10,
    Ace     =   1
};

class Card {
private:
    Suit suit;
    Rank rank;
    bool face;
    Card() = default;
public:
    Card(Suit _suit, Rank _rank, bool _face = false) : suit(_suit), rank(_rank), face(_face) {};
    void Flip(){
        face = !face;
    };
    int GetValue(){
        return (int)rank;
    }
};

