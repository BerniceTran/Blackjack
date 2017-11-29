#include "Stack.h"
#include "Card.h"
#include <iostream>
#include<ctime>
#include <random>
using namespace std;

Stack::Stack()
{
    capacity = STANDARD_NUMBER;
    size = STANDARD_NUMBER;
    cardsOnStack = new Card*[capacity];
    int h = 0;
    
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 13; j++)
            {
                cardsOnStack[h++] = new Card(i, j);
            }
        }
}

Stack::Stack(int c)
{
    size = c*STANDARD_NUMBER;
    capacity = c*STANDARD_NUMBER;
    cardsOnStack = new Card*[capacity];
    int h = 0;
    for (int p = 0; p < capacity; p++)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j= 0; j < 13; j++)
            {
                cardsOnStack[h++] = new Card(i, j);
            }
        }
    }
}

Stack::Stack(const Stack& other)
{
    size = other.size;
    capacity = other.capacity;
    
    cardsOnStack = new Card*[capacity];

    for (int h = 0; h < capacity; h++)
    {
        cardsOnStack[h] = new Card(*other.cardsOnStack[h]);
    }

}

Stack::~Stack() 
{
    cout << "~Stack()" << endl;
    for (int h = 0; h < size; h++)
        delete cardsOnStack[h];
    delete [] cardsOnStack;
}

Stack& Stack::operator=(const Stack& other)
{
    cout << "Stack& Stack::operator=" << endl;

    if ( this == &other)
        return *this;
    else
    {
    size = other.size;
    capacity = other.capacity;
    
        for (int i = 0; i < size; i++)
        {
            delete cardsOnStack[i];
        }
        delete[] cardsOnStack;
    
    cardsOnStack = new Card*[capacity];
    
        for (int i = 0; i < other.size; i++)
        {
            cardsOnStack[i] = new Card(*other.cardsOnStack[i]); // possibly problematic
        }
        return *this;
    }
}

Card** Stack:: getCards() const
{
    return cardsOnStack;

}

int Stack::getCapacity() const
{
    return capacity;
}


int Stack::getSize() const
{
    return size;
}

void Stack:: setCapacity(int c)
{
    capacity = c;
}

void Stack::setSize(int s)
{
    size = s;
}


bool Stack::isEmpty()
{
    return size == 0;
}

bool Stack::isFull()
{
    return size == capacity;
}

Card* Stack::peek() // peek and pop have exactly the same code, is that right?
{
   if(!isEmpty())
       return cardsOnStack[size - 1];
    else
    {
        return NULL;
    }
}

Card* Stack::pop()
{
    if(!isEmpty())
    {
        return cardsOnStack[--size];
        
    }
    else
    {
        return NULL;
    }
}

void Stack::push(Card* c)
{
    if(!isFull())
    {
        cardsOnStack[size] = c;
        size++;
    }
    cout << "Stack is full.";
}

void Stack::display()
{
    for (int i = 0; i  < capacity; i++)
    {
        
        cardsOnStack[i]->display();
    }
}

void Stack::mix()
{
    /* initialize random seed: */
    srand( static_cast<unsigned int>(time(NULL)));
    
    for(int i = 0; i < 100; ++i) {
    
        int num1 = rand() % size;
        int num2 = rand() % size;
        swap(cardsOnStack[num1], cardsOnStack[num2]);
    }

}

void Stack:: swap(Card*& c1, Card*& c2)
{

    Card* temp = c1;
    c1 = c2;
    c2 = temp;

}








