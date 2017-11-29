/*
#ifndef player_h
#define player_h

#include "hand.h"
#include <iostream>

using namespace std;

class Player
{
private:
    Hand* hand;
    string firstName;
    string lastName;
    int highScore;
    bool isHuman;
public:
    Player();
    Player(string fName, string lName);
    ~Player();
    Player& operator=(Player&);
    
    //Gives game access to player hand
    Hand* getHand();
    void setHand(Hand*);
    
    //Encapsulates player's hand
    int getTotal()
    {
        return hand->evaluate();
    }

};



#endif  player_h */


#ifndef PLAYER_H
#define PLAYER_H

#include "Hand.h"
#include <iostream>

using namespace std;

class Player
{
private:
    string name;
    Hand* hand;
    int points;
public:
    Player();
    Player(string name);
    void setName(string name);
    string getName() const;
    
    void addCard(Card*);
    
    //get total value - if over 21 check for Aces of value 11 and convert to value 1
    int evaluate();

    //Encapsulates player's hand
    int getTotal();
    void setPoints(int points);
    int getPoints() const;
    
    void showHand();
    
    ~Player();
    
};

#endif