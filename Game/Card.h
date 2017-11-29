#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card
{
private:
    //suit is represented with values 0-3
    int suit;
    //rank is represented with values 0-12
    int rank;
    //int value;
    int value;
public:
    Card();
    Card(int, int);
    int getSuit();
    int getRank();
    void setSuit(int);
    void setRank(int);
    int compareByValue(const Card& other);
    int compareByRank(const Card& other);
    int compareBySuit(const Card& other);
    int compareTo(const Card& other);
    string getRankAsString() const;
    string getSuitAsString() const;
    void display();
    friend ostream& operator <<(ostream&, const Card& c);
};

#endif
