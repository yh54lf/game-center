#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mainMenu.h"
#include "C:\Users\Benjamin\Desktop\CS 103\CS103_Project_GameCenter\Minesweeper\minesweeper.cpp"
#include "C:\Users\Benjamin\Desktop\CS 103\CS103_Project_GameCenter\HorseRace\horseRace.cpp"
#include "C:\Users\Benjamin\Desktop\CS 103\CS103_Project_GameCenter\Blackjack\blackJack.cpp"

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
    cout << "\t \t \t 1. Horse Race - 5points" << endl;
    pause(1);
    cout << "\t \t \t 2. Minesweeper - 10points" << endl;
    pause(1);
    cout << "\t \t \t 3. BlackJack - 10points" << endl;
    pause(1);
    cout << "\t \t \t 4. Go Back " << endl;
    cout << "****************************************************************" << endl;
    GameCenter::handleUserChoiceGames();
}

void GameCenter::handleUserChoiceGames()
{
    int choice = GameCenter::userChoice();
    if (choice == 1)
    {
        if (userPoints >= 5)
        {
            userPoints = userPoints - 5;
            Race start;
            bool checkWinner = start.start();
            if (checkWinner == true)
                userPoints += 15;

            pause(2);
            GameCenter::printGames();
        }
        else
        {
            cout << "You don't have enough points to play this game :(" << endl;
            pause(2);

            GameCenter::printGames();
        }
    }

    else if (choice == 2)
    {
        if (userPoints >= 10)
        {
            userPoints = userPoints - 10;
            Minesweeper start;
            bool checkWinner = start.playMinesweeper();
            if (checkWinner == true)
                userPoints += 20;

            pause(2);
            GameCenter::printGames();
        }
        else
        {
            cout << "You don't have enough points to play this game :(" << endl;
            pause(2);

            GameCenter::printGames();
        }
    }
    else if (choice == 3)
    {
        if (userPoints >= 10)
        {
            userPoints = userPoints - 10;
            Blackjack start;
            bool checkWinner = start.playGame();
            if (checkWinner == true)
                userPoints += 20;

            pause(2);
            GameCenter::printGames();
        }
        else
        {
            cout << "You don't have enough points to play this game :(" << endl;
            pause(2);
            GameCenter::printGames();
        }
    }
    else if (choice == 4)
    {
        // if user chooses Back option, he gets returned to main menu
        GameCenter::printMainMenu();
    }

    else
    {
        // Invalid choice
        cout << "Invalid choice" << endl;
        cout << endl;
        GameCenter::printGames();
    }
}

int GameCenter::userChoice()
{
    // Returns the choice user enters
    cout << "Enter your choice: ";
    int choice;
    cin >> choice;
    return choice;
}
void GameCenter::printMainMenu()
{
    // Display the main menu for the game center
    cout << endl;
    cout << "***************Welcome to the game center!***************" << endl;
    cout << "Points: " << GameCenter::userPoints << endl;
    cout << "\t \t \t 1. Play a game" << endl;
    cout << "\t \t \t 2. Quit" << endl;
    cout << "*********************************************************" << endl;
    GameCenter::handleUserChoiceMainMenu();
}
void GameCenter::handleUserChoiceMainMenu()
{
    int choice = GameCenter::userChoice();
    if (choice == 1)
    {
        // List the available games in the game center

        printGames();
    }
    // if user chooses Back option, he gets returned to main menu

    else if (choice == 2)
    {
        // Quit the program
        cout << endl;
        cout << "Thank you for using the game center!" << endl;
        pause(1);
        cout << "You have " << GameCenter::userPoints << " points." << endl;
        pause(1);
        cout << "Goodbye <3" << endl;
        pause(2);
    }

    else
    {
        // Invalid choice
        cout << "Invalid choice" << endl;
        cout << endl;
        GameCenter::printMainMenu();
    }
}

void GameCenter::pause(int dur)
{
    int temp = time(NULL) + dur;
    while (temp > time(NULL))
        ;
}
void GameCenter::play()
{
    printMainMenu();
}
