/*C++ program to develope a code for Guessing the Number from 1 to 100*/
//Task 2
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
    cout << "\n\t\t\tWelcome to GuessTheNumber game!!!!" << endl;
    cout << "You have to guess a number between 1 and 100. " << endl;

    while (true) {
        cout << "\nEnter the difficulty level: \n";
        cout << "1. Easy\t";
        cout << "2. Medium\t";
        cout << "3. Difficult\t";
        cout << "0. End the game\n" << endl;

        // Select the level of difficulty
        int difficultyChoice;
        cout << "Enter your choice (0, 1, 2, 3): ";
        cin >> difficultyChoice;

        if (difficultyChoice == 0) {
            exit(0); // End the game
        }

        // Generating the secret number
        srand(time(0));
        int secretNumber = 1 + (rand() % 100);
        int playernumChoice;

        // Set the number of choices based on the difficulty level
        int maxAttempts;
        switch (difficultyChoice) {
            case 1:
                cout << "\nYou have 10 choices for finding the secret number between 1 and 100." << endl;
                maxAttempts = 10;
                break;
            case 2:
                cout << "\nYou have 7 choices for finding the secret number between 1 and 100." << endl;
                maxAttempts = 7;
                break;
            case 3:
                cout << "\nYou have 5 choices for finding the secret number between 1 and 100." << endl;
                maxAttempts = 5;
                break;
            default:
                cout << "Wrong choice. Enter a valid choice to play the game! (0, 1, 2, 3)" << endl;
                continue; // Go to the next iteration of the loop
        }

        bool found = false;

        for (int attempt = 1; attempt <= maxAttempts; attempt++) {
            // Prompting the player to guess the secret number
            cout << "\n\nEnter your guess: ";
            cin >> playernumChoice;

            // Determine if the player's choice matches the secret number
            if (playernumChoice == secretNumber) {
                cout << "Congratulations! You won. " << playernumChoice << " is the secret number." << endl;
                cout << "\t\t\tThanks for playing." << endl;
                cout << "Play the game again with us!\n\n" << endl;
                found = true;
                break;
            } else {
                cout << "Nope, " << playernumChoice << " is not the correct number." << endl;
                if (playernumChoice > secretNumber) {
                    cout << "The secret number is smaller than the number you have chosen." << endl;
                } else {
                    cout << "The secret number is greater than the number you have chosen." << endl;
                }
                cout << maxAttempts - attempt << " choices left." << endl;
            }
        }

        if (!found) {
            cout << "You couldn't find the secret number. It was " << secretNumber << ". You lose!" << endl;
            cout << "Play the game again to win!\n\n" << endl;
        }
    }

    return 0;
}


