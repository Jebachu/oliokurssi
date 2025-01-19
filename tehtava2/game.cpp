#include "game.h"
#include <ctime>

Game::Game(int mn)
{
    maxNumber = mn;
    cout << "Game konstruktori "
        << "maxNumber on "
        << maxNumber
         << endl;

}


Game::~Game()
{
    cout << "Game destruktori"
         << endl;
}

void Game::printGameResult()

{

    cout<< "Correct! Right answer is "
         << playerGuess
         << endl;

    cout<< "number of guesses "
         << numOfGuesses
         << endl;

}


void Game::play()


    {
    cout << "Game play"
         << endl;



    srand(std::time(0));
    int randomNumber = (rand()%maxNumber)+1;
    int playerGuess;
    bool stayInLoop = true;
    int numOfGuesses = 0;

    while(stayInLoop)
    {
        cout<<"Guess a number between 1-"<<maxNumber<<endl;
        cin>>playerGuess;
        numOfGuesses++;

        if(playerGuess == randomNumber)
        {

            printGameResult();
            {

                cout<<playerGuess<<endl;
                cout<<numOfGuesses<<endl;

            }

            stayInLoop = false;


        }
        else if(playerGuess<randomNumber)
        {
            cout<<"Your number is too small"<<endl;
        }
        else
        {
            cout<<"Your number is too big"<<endl;
        }


    }




}





















