#include "Hand.h"

Hand::Hand()
{
    hand = new LinkedList;
}
Hand::Hand(Hand&)
{
    
}

Hand::~Hand()
{
    delete hand;
    hand = NULL;
}

int Hand::getCount()
{
    return hand->getSize();
}

void Hand::insertByRank(Card*) // not important in blackjack
{
    
}

void Hand::insertLast(Card* card)
{
    
    hand->insertAtTail(card);
}
void Hand::remove(Card*) //not important in blackjack
{
    
}



bool Hand::isEmpty()
{
    return hand->isEmpty();
}

void Hand::printHand()
{
    hand->printList();
}


int Hand::evaluate() // gets the total of all the cards in the players hands and decides what to do with the aces (1 or 11)
{
    int total =  0;
    bool ace = false;
    for (int i = 0; i < hand->getSize(); i++)
    {
        Card* temp = hand -> getAtIndex(i);
        int value = temp -> getRank();
        if (value <= 8)
            value++;
        else
            value = 10;
        
        
        if(!ace && value==1)
        {
            ace=true;
        }
        total+=value;
    }
    
    if(ace && total+10<22)
    {
        total+=10;
    }
    
    return total;
}

int Hand::compare(Hand& other)
{
    if (this -> evaluate() > other.evaluate())
        return 1;
    if (this -> evaluate() == other.evaluate())
        return 0;
    else
        return -1;
}








