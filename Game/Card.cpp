#include "Card.h"

Card::Card() : rank(0), suit(0)
{
    //Empty
}

Card::Card(int s, int r)
{
    suit = s;
    rank = r;
}

int Card::getSuit()
{
    return suit;
}

int Card::getRank()
{
    return rank;
}
void Card::setSuit(int suit)
{
    this -> suit = suit;
}

void Card::setRank(int rank)
{
    this -> rank = rank;
}

int Card::compareBySuit(const Card& other)
{
    return suit = other.suit;
}

int Card::compareByRank(const Card& other)
{
    return rank = other.rank;
}

int Card::compareTo(const Card& other)
{
    if (rank == other.rank)
        return suit - other.rank;
    return rank - other.rank;
}
                    
string Card::getRankAsString() const
{
    string ranks[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    return ranks[rank];
}

string Card::getSuitAsString() const
{
    string suits[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    return suits[suit];
}
                    
void Card::display()
{
    cout << getRankAsString() << " of " << getSuitAsString() << endl;
}

ostream& operator <<(ostream& out, const Card& c)
{
    return out << c.getRankAsString() << " of " << c.getSuitAsString() << endl;
}


