#include <iostream>
#include <windows.h>

using namespace std;
class GameCenter
{
private:
    int points;

public:
    GameCenter();
    int userPoints;
    void handleUserChoiceGames();
    void printMainMenu();
    void handleUserChoiceMainMenu();
    void printGames();
    string userChoice();
    void pause(int dur);
    void play();
    int bet();
};
