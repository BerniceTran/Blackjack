#ifndef HAND_H
#define HAND_H

#include "LinkedList.h"
#include <iostream>

using namespace std;

class Hand
{
private:
    LinkedList* hand;
    
public:
    Hand();
    Hand(Hand&);
    ~Hand();
    Hand& operator=(Hand&);
    int getCount();
    void insertByRank(Card*);
    void insertLast(Card*);
    void remove(Card*);
    bool isEmpty();
    void printHand();
    
    //Blackjack
    int evaluate();
    int compare(Hand&);
};

#endif