#include "Game.h"
#include <iostream>

void DeckDriver();
void LinkListDriver();
void HandDriver();
int main()
{
   Blackjack* game = new Blackjack();
   game->start();
   delete game;

    //DeckDriver();
    //LinkListDriver();
    //HandDriver();
    
    
}

void DeckDriver()
{
    Deck yourDeck(5);
    
    cout << "Before shuffle: OurDeck " << endl;
    yourDeck.display();
    cout << endl;
    
    cout << "After Shuffle:" << endl << endl << endl << endl;
    yourDeck.shuffle();
    
    cout << endl << endl << "Demonstration of pop:" << endl;
    cout << *(yourDeck.deal()) << endl;
    cout << *(yourDeck.deal()) << endl;
    cout << *(yourDeck.deal())  << endl;
    
    cout <<"Demonstration of ostream: " << endl;
    cout << yourDeck;
}

void LinkListDriver()
{
    LinkedList myList;
    myList.insertAtHead(new Card(0,0));
    myList.insertAtHead(new Card(0,1));
    myList.insertAtHead(new Card(0,2));
    myList.insertAtTail(new Card(0,3));
    myList.insertAtIndex(new Card(0,4),2);
    
    myList.printList();
    
    for(int i = 0; i < myList.getSize(); i++)
    cout << *myList.getAtIndex(i) << endl;
    
     cout << "Removing " <<  *myList.removeAtHead();
    myList.printList();
    cout << endl;
    
    cout << "Removing " <<  *myList.removeAtIndex(2);
    myList.printList();
    cout << endl;
    
     cout << "Removing " <<  *myList.removeAtTail();
    myList.printList();
    
}

void HandDriver()
{
    Deck myDeck;
    myDeck.shuffle();
    
    Hand player1;
    for (int i = 0; i < 2; i++)
    {
        Card* card = myDeck.deal();
        
        player1.insertLast(card);
    }

    cout << "Player 1 hand: " << endl;
    player1.printHand();
    
    Hand player2;
    
    for (int i = 0; i < 2; i++)
    {
        Card* card = myDeck.deal();
        player2.insertLast(card);
    }
    
    cout << "Player 2 hand: " << endl;
    player2.printHand();
    
    int player1_total = player1.evaluate();
    int player2_total = player2.evaluate();
    
    cout << "Player 1 total: " << player1_total << endl;
    cout << "Player 2 total: " << player2_total << endl;
    
    if(player1.compare(player2) == 1)
        cout << "Player1 has the larger hand." << endl;
    else if(player2.compare(player1) == 1)
        cout <<  "Player2 has the larger hand." << endl;
    else
        cout << "Both players hands are the same." << endl;

}
