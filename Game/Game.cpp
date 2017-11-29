#include "Game.h"
#include "Game.h"

string playerName;

Blackjack::Blackjack()
{

}

void Blackjack:: start()
{
    bool gameOn = true;
    
    do{
        cout << endl;
        cout << "MAIN MENU" <<  endl;
        cout << "1) Start game. " << endl;
        cout << "2) Exit." <<  endl;
        
        int choice;
        cin >> choice;
       
        switch(choice)
        {
            case 1:
            {
                this->play();
                break;
            }
            case 2:
            {
                gameOn = false;
                break;
            }
        
        }
        
    }while (gameOn);
    
    cout <<  "Thank you for playing!" << endl;

}

void Blackjack::play()
{
    
    cout << "******** Welcome to Blackjack ********" << endl;
    cout << "Enter your name: ";
    cin >> playerName;
    //numOfGamesPlayed = 0; numOfWins = 0; numOfLose = 0; numOfDraw = 0;
        
    //cout << "Name: " << playerName << " || Games played: " << numOfGamesPlayed << " || Wins: " << numOfWins << " || Loses: " << numOfLose << " || Tie Games: " << numOfDraw << endl;
    
    CPU = new Player();
    Human = new Player(playerName);
    
    Deck gameDeck(5);
    gameDeck.shuffle();
    
    for (int i = 0; i < 2; i++)
    {
        Card* card = gameDeck.deal();
        Human->addCard(card);
    }
    
    for (int i = 0; i < 2; i++)
    {
        Card* card = gameDeck.deal();
        CPU->addCard(card);
    }
    
    cout << "My cards: " << endl;    
    Human->showHand();
    if(Human -> getTotal() == 21)
    {
        cout << "Blackjack!" << endl;
        cout << Human->getName() <<  " wins!";
        return;
    
    }
    
    char option;

    cout << "Would you like to stand or hit? (S/H)" << endl;
    cin >> option;
    
    bool playerBust = false;
    bool cpuBust = false;
    bool cpuWin = false;
    
    while (!playerBust && (option == 'H' || option == 'h'))
    {
        Card* card = gameDeck.deal();
        Human->addCard(card);
        Human->showHand();
        if (Human->getTotal()>21)
        {
            
            cout << "Your total is " << Human->getTotal() << "." << endl;
            cout << "Bust!" << endl;
            playerBust = true;
            continue;
        }
        cout << "Would you like to stand or hit? (S/H)" << endl;
        cin >> option;
    }
    
    if (!playerBust)
    {
        //Human->showHand();
        cout << "Your total is " << Human->getTotal() << "." << endl;
    
        while (!cpuWin && !cpuBust  && CPU->getTotal() < Human->getTotal())
        {
            CPU->addCard(gameDeck.deal());
            if (CPU->getTotal()>21)
            {
                cpuBust = true;
            }
            else if (CPU->getTotal()==21  || CPU->getTotal() > Human->getTotal())
            {
                cout << "The CPU has Blackjack" << endl;
                cpuWin = true;
            }
//            else if (CPU->getTotal() > Human->getTotal())
//            {
//                cpuWin = true;
//            }
        }
        
        cout << "CPU hand: " << endl;
        CPU->showHand();
        
        if (cpuBust)
        {
            cout << "CPU total: " << CPU->getTotal() << endl;
            cout << "You win!" << endl;
        }
        else if (cpuWin)
        {
            cout << "CPU total: " << CPU->getTotal() << endl;
            cout << "CPU wins!" << endl;
        }
        else
        {
            cout << "CPU total: " << CPU->getTotal() << endl;
            cout << "Tie!" << endl;

        }
    }
    
    
    
    
    
}