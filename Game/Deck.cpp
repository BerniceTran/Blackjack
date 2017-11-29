#include "Deck.h"

Deck::Deck()
{
    deck = new Stack;
    
}
Deck::Deck(int decks)
{
    deck = new Stack(decks);
}
void Deck::shuffle()
{
    deck -> mix();
    
}

void Deck::swap(Card* c, Card* d)
{
    Card* temp = c;
    c = d;
    d = temp;
}

int Deck::getCount()
{
    return deck -> getSize();
}

Card* Deck::deal()
{
   return deck -> pop();
}

void Deck::display() const
{
    deck -> display();
}

ostream& operator <<(ostream& out, const Deck& d)
{
    return out << d.deck;
}
