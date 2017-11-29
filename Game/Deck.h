#ifndef DECK_H
#define DECK_H

#include "Stack.h"
#include "Card.h"

class Deck
{
private:
    Stack* deck;
    void swap(Card* c, Card* d);
    
public:
    Deck();
    Deck (int);
    void shuffle();
    void display() const;
    int getCount();
    Card* deal();
    friend ostream& operator <<(ostream&, const Deck&);
};

#endif