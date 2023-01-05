#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "mainMenu.h"
#include "C:\Users\Benjamin\Desktop\games\game-center\Minesweeper\minesweeper.cpp"
#include "C:\Users\Benjamin\Desktop\games\game-center\HorseRace\horseRace.cpp"
#include "C:\Users\Benjamin\Desktop\games\game-center\Blackjack\blackJack.cpp"

GameCenter::GameCenter()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);
    points = 100;
    userPoints = points;
}

void GameCenter::printGames()
{
    cout << endl;
    cout << "***************What game would you like to play?***************" << endl;
    cout << "Points: " << GameCenter::userPoints << endl;
    pause(1);
    cout << "\t \t \t 1. Horse Race" << endl;
    pause(1);
    cout << "\t \t \t 2. Minesweeper" << endl;
    pause(1);
    cout << "\t \t \t 3. BlackJack" << endl;
    pause(1);
    cout << "\t \t \t 4. Go Back " << endl;
    cout << "****************************************************************" << endl;
    GameCenter::handleUserChoiceGames();
}

void GameCenter::handleUserChoiceGames()
{
    string choice = GameCenter::userChoice();
    if (choice == "1")
    {
        int userBet = GameCenter::bet();

        Race start;
        bool checkWinner = start.start();
        if (checkWinner == true)
        {
            cout << "You earn " << userBet * 2 << "points!" << endl;
            userPoints += userBet * 2;
        }
        else
            userPoints -= userBet;

        pause(2);
        GameCenter::printGames();
    }

    else if (choice == "2")
    {
        int userBet = GameCenter::bet();

        Minesweeper start;
        bool checkWinner = start.playMinesweeper();
        if (checkWinner == true)
        {
            cout << "You earn " << userBet * 2 << "points!" << endl;
            userPoints += userBet * 2;
        }
        else
            userPoints -= userBet;

        pause(2);
        GameCenter::printGames();
    }
    else if (choice == "3")
    {
        int userBet = GameCenter::bet();
        Blackjack start;
        bool checkWinner = start.playGame();
        if (checkWinner == true)
        {
            cout << "You earn " << userBet * 2 << "points!" << endl;
            userPoints += userBet * 2;
        }
        else
            userPoints -= userBet;

        pause(2);
        GameCenter::printGames();
    }

    else if (choice == "4")
    {
        // if user chooses Back option, he gets returned to main menu
        GameCenter::printMainMenu();
    }

    else
    {
        // Invalid choice
        cout << "Invalid choice" << endl;
        cout << endl;
        pause(2);

        GameCenter::printGames();
        return;
    }
}

string GameCenter::userChoice()
{
    bool test = true;
    string choice;
    // Returns the choice user enters
    while (test)
    {
        cout << "Enter your choice (number): ";

        getline(cin, choice);
        cout << endl;
        if (choice.length() != 1)
        {
            cout << "Please enter a single choice." << endl;
            pause(1);

            cout << endl;
        }
        else
            test = false;
    }

    return choice;
}
void GameCenter::printMainMenu()
{
    // Display the main menu for the game center
    cout << endl;
    cout << "***************Welcome to the game center!***************" << endl;
    pause(1);

    cout << "Points: " << GameCenter::userPoints << endl;
    pause(1);

    cout << "\t \t  1. Play a game" << endl;
    pause(1);

    cout << "\t \t  2. Quit" << endl;
    pause(1);

    cout << "*********************************************************" << endl;
    GameCenter::handleUserChoiceMainMenu();
}
void GameCenter::handleUserChoiceMainMenu()
{

    string choice = GameCenter::userChoice();

    if (choice == "1")
    {
        // List the available games in the game center

        printGames();
    }
    // if user chooses Back option, he gets returned to main menu

    else if (choice == "2")
    {
        // Quit the program
        cout << endl;
        cout << "Thank you for using the game center!" << endl;
        pause(1);
        cout << "You have " << GameCenter::userPoints << " points." << endl;
        pause(1);
        cout << "Goodbye <3" << endl;
        GameCenter::~GameCenter();
        pause(1000000);
    }

    else
    {
        // Invalid choice
        cout << "Invalid choice" << endl;
        pause(2);

        cout << endl;
        GameCenter::printMainMenu();
    }
}

int GameCenter::bet()
{
    int bet;
    bool check = true;
    while (check)
    {
        cout << endl;
        cout << "How much points do you want to bet (type 0 to go back): ";
        cin >> bet;
        cout << endl;
        if (bet > userPoints)
        {
            cout << "You do not have enough points!" << endl;
        }
        else if (bet == 0)
            GameCenter::printGames();
        else
        {
            check = false;
        }
    }
    return bet;
}

void GameCenter::pause(double dur)
{
    int temp = time(NULL) + dur;
    while (temp > time(NULL))
        ;
}
void GameCenter::play()
{
    printMainMenu();
}
