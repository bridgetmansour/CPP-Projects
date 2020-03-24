#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;
const int WINNING_SCORE = 100;


//Implements the printIntro function
void printIntro () {
    cout << "Welcome to the dice game Pig!";
    cout << endl;
    cout << "The objective is to be first to score 100 points.";
    cout << endl << endl;
    
    return;
}

//Implements the humanTurn function
int humanTurn (string playerName, int playerScore, int& diceRoll, char& playerInput) {
    diceRoll = ((rand() % 6) + 1);
    while ((playerInput == 'y') && (diceRoll != 1)) {
         cout << playerName << endl;
         cout << "You rolled a " << diceRoll << endl;
         playerScore = playerScore + diceRoll;
         cout << "Your score: " << playerScore << endl;
            if (playerScore < 100) {
            cout << "Do you want to roll again? (y/n): ";
            cin  >> playerInput;
            cout << endl;
            }
            if (playerInput == 'n') {
                return playerScore;
            }
    }
            if (diceRoll == 1) {
            cout << playerName << endl;
            cout << "You rolled a 1 (PIG!)" << endl;
            cout << "Your turn is over" << endl;
            cout << "Your score: " << playerScore << endl << endl;
            return 0;
}

int main() {
    srand(4444);

    // Sets up and initializes variables
    int turn = PLAYER1;
    int player1score = 0;
    int player2score = 0;
    string player1name;
    string player2name;
    char playerInput = 'y';
    int diceRoll;

    printIntro();

    // Gets names of players
    cout << "Player 1 - Enter your name: ";
    cin  >> player1name;
    cout << endl;
    cout << "Player 2 - Enter your name: ";
    cin  >> player2name;
    cout << endl;


    //plays game
    while (player1score < WINNING_SCORE && player2score < WINNING_SCORE) {

        //player 1's turn or player 2's turn
        if (turn == PLAYER1) {
            player1score = humanTurn(player1name, player1score, diceRoll, playerInput);
        }
        else {
            player2score = humanTurn(player2name, player2score, diceRoll, playerInput);
        }

        //switches whose turn it is
        if (( diceRoll == 1) || playerInput == 'n' ) {
            if (turn == PLAYER1) {
                turn = PLAYER2;
            }
            else if (turn == PLAYER2) {
                turn = PLAYER1;
            }
        }

    }

cout << endl;

    // Outputs who won the game.

    if (player1score > player2score) {
        cout << player1name << " wins!" << endl;
    }
    else {
        cout << player2name << " wins!" << endl;
    }

    return 0;
}