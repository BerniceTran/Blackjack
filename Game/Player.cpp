#include "Player.h"

Player::Player()
{
    name = "none";
    hand = new Hand;
    points = 0;
}

Player::Player(string name)
{
    this->name = name;
    hand = new Hand;
}

Player::~Player()
{
    delete hand;
}

void Player::setName(string name)
{
    this->name = name;
}

string Player::getName() const
{
    return name;
}

void Player::addCard(Card* c)
{
    hand->insertLast(c);
}

void Player::showHand()
{
    hand -> printHand();
}


int Player::getTotal() //Encapsulates player's hand
{
    return hand->evaluate();
}

void Player::setPoints(int points)
{
    this->points = points;
}

int Player::getPoints() const
{
    return points;
}