#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
    tail = head;
    size= 0;
}

LinkedList::LinkedList(LinkedList& other)
{
    //head = new Node(new Card(other.head->getData()->getSuit(), other.head->getData()->getRank())
    head = other.head;
    tail = other.tail;
    size = other.size;
}


Card* LinkedList::getHead() const
{
    return head->getData();
}

Card* LinkedList::getTail() const
{
    return tail->getData();
}

Card* LinkedList::getAtIndex(int index) const
{
    if (index >= size || index < 0)
        return NULL;
    if (index == 0)
        return getHead();
    if (index == size -1)
        return getTail();
    Node* current = head;
    
    for (int i = 0; i < index; i++)
        current = current->getNext();
    
    return current->getData();
        
    
}

int LinkedList::getSize() const
{
    return size;
}

void LinkedList::insertAtHead(Card* data)
{
    if(isEmpty()){
        head = new Node(data);
        tail = head;
    }
    else
        head = new Node(data, head);
    
    
    size++;
        
}
void LinkedList::insertAtTail(Card* data)
{
    if (isEmpty())
        insertAtHead(data);
    else {
        tail->setNext(new Node(data));
        tail = tail->getNext();
        size++;
    }

}
bool LinkedList::insertAtIndex(Card* data, int index)
{
    if (index < 0 || index > size)
    {
        cerr << "InsertAtIndex: index out of bounds" << endl;
        return NULL;
    }
    if (index == 0)
        insertAtHead(data);
    else if (index == size)
        insertAtTail(data);
    else
    {
        Node* trav = head;
        for (int i = 0; i < index - 1; i++)
            trav = trav->getNext();
        trav->setNext(new Node(data, trav->getNext()));
        size++;
    }
    
    return true;

}
Card* LinkedList::removeAtHead()
{
    if (head == NULL)
        return NULL;
    
    Node * temp = head;
    
    if (head == tail)
    {
        tail = NULL;
    }
    
    head= head->getNext();
    size--;
    return temp->getData();
}
Card* LinkedList::removeAtTail()
{
    if (tail == NULL)
        return NULL;
    
    if (head == tail)
    {
        return removeAtHead();
    }
    
    Node * rval = tail;
    Node * temp = head;
    while (temp->getNext()->getNext() != NULL)
    {
        temp = temp->getNext();
    }
    temp->setNext(NULL);
    tail = temp;
    size--;
    return rval->getData();
    
}
Card* LinkedList::removeAtIndex(int index)
{
    if (index < 0 || index > size)
    {
        
        return NULL;
    }
    if (index == 0)
        return removeAtHead();
    else if (index == size)
        return removeAtTail();
    else
    {
        Node* trav = head;
        for (int i = 0; i < index-1; i++)
            trav = trav->getNext();
        
        Node* rval = trav->getNext();
        
        trav->setNext(trav->getNext()->getNext());
        
        rval->setNext(NULL);
        size--;
        return rval->getData();
    }
}

bool LinkedList::isEmpty()
{
    return size == 0;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if (this == &other)
        return *this;
    else
    {
        head = other.head;
        tail = other.tail;
        size = other.size;
    }
    
    return *this;
        
}

LinkedList::~LinkedList()
{
   
}

void LinkedList::printList()
{
    if(size==0) return;
    
    Node * temp = head;
    
    while (temp!=NULL) {
        cout << *temp->getData();
        temp = temp->getNext();
    }
    
}


