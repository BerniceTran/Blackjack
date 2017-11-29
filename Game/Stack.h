#ifndef STACK_H
#define STACK_H
#define STANDARD_NUMBER 52

#include "Card.h"

class Stack
{
private:
    Card** cardsOnStack;
    int capacity;
    int size;
    void swap(Card*& c1, Card*& c2);
public:
    Stack();
    Stack(int cap);
    Stack(const Stack& other);
    ~Stack();
    Stack& operator=(const Stack& other);
    Card** getCards() const;
    int getCapacity() const;
    int getSize() const;
    void setCapacity(int c);
    void setSize(int s);
    void push(Card c);
    Card* pop();
    Card* peek();
    void push(Card* c);
    void mix();
    bool isEmpty();
    bool isFull();
    void display();
    friend ostream& operator <<(ostream&, const Stack&);
};

#endif

