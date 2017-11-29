#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
    Node *head;
    Node *tail;
    int size;
public:
    LinkedList();
    LinkedList(LinkedList& otherList);
    Card* getHead() const;
    Card* getTail() const;
    Card* getAtIndex(int) const;
    int getSize() const;
    void insertAtHead(Card* data);
    void insertAtTail(Card* data);
    bool insertAtIndex(Card* data, int index);
    void removeCards();
    Card* removeAtHead();
    Card* removeAtTail();
    Card* removeAtIndex(int index);
    Card* remove(Card* data);
    bool contains(Card* data);
    int search(Card* data);
    bool isEmpty();
    const Card& operator[](int index);
    friend ostream& operator<<(ostream&, LinkedList&);
    LinkedList& operator=(const LinkedList&);
    ~LinkedList();
    void printList();
    
    
    
    
};
#endif
