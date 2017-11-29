#ifndef GAME_H
#define GAME_H

#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"

class Blackjack
{
private:
    Player* CPU;
    Player* Human;
    Deck bJack;
public:
    Blackjack();
    void start();
    void play();
    bool checkWin(Player*);
};

#endif