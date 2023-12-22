/*TicTacToe Game in C++*/
//Task 3
#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
using namespace std;

// Function prototypes
void resetBoard();           // Reset the Tic Tac Toe board to an empty state
void printBoard();           // Display the current state of the Tic Tac Toe board
int checkFreeSpaces();        // Check the number of free spaces on the board
void playerMove();           // Allow the player to make a move on the board
void computerMove();         // Simulate the computer's move on the board
char checkWinner();          // Check if there is a winner on the current board
void printWinner(char);       // Display the winner of the game

// Global variables
char board[3][3];             // 2D array to represent the Tic Tac Toe board
const char PLAYER = 'X';      // Symbol for the player
const char COMPUTER = 'O';    // Symbol for the computer

// Main function
int main()
{
   char winner = ' ';
   char response = ' ';

   // Main game loop
   do
   {
      winner = ' ';
      response = ' ';
      resetBoard();   // Initialize the board

      // Game loop for a single game
      while(winner == ' ' && checkFreeSpaces() != 0)
      {
         printBoard();

         playerMove();        // Player makes a move
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }

         computerMove();      // Computer makes a move
         winner = checkWinner();
         if(winner != ' ' || checkFreeSpaces() == 0)
         {
            break;
         }
      }

      printBoard();
      printWinner(winner);

      cout<< "\nWould you like to play again? (Y/N): ";
      cin>> response;
      response = toupper(response);
   } while (response == 'Y');

   printf("Thanks for playing!");

   return 0;
}

// Function to reset the Tic Tac Toe board to an empty state
void resetBoard()
{
   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         board[i][j] = ' ';
      }
   }
}

// Function to display the current state of the Tic Tac Toe board
void printBoard()
{
   cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
   cout << "---|---|---\n";
   cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
   cout << "---|---|---\n";
   cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

// Function to check the number of free spaces on the board
int checkFreeSpaces()
{
   int freeSpaces = 9;

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         if(board[i][j] != ' ')
         {
            freeSpaces--;
         }
      }
   }
   return freeSpaces;
}

// Function to allow the player to make a move on the board
void playerMove()
{
   int x;
   int y;

   do
   {
      cout << "Enter row #(1-3): ";
      cin >> x;
      x--;
      cout << "Enter column #(1-3): ";
      cin >> y;
      y--;

      if(board[x][y] != ' ')
      {
         cout << "Invalid move!\n";
      }
      else
      {
         board[x][y] = PLAYER;
         break;
      }
   } while (board[x][y] != ' ');
}

// Function to simulate the computer's move on the board
void computerMove()
{
   srand(time(0));
   int x;
   int y;

   if(checkFreeSpaces() > 0)
   {
      do
      {
         x = rand() % 3;
         y = rand() % 3;
      } while (board[x][y] != ' ');

      board[x][y] = COMPUTER;
   }
   else
   {
      printWinner(' ');
   }
}

// Function to check if there is a winner on the current board
char checkWinner()
{
   for(int i = 0; i < 3; i++)
   {
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
      {
         return board[i][0];
      }
   }

   for(int i = 0; i < 3; i++)
   {
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
      {
         return board[0][i];
      }
   }

   if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
   {
      return board[0][0];
   }

   if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
   {
      return board[0][2];
   }

   return ' ';
}

// Function to display the winner of the game
void printWinner(char winner)
{
   if(winner == PLAYER)
   {
      cout << "YOU WIN!";
   }
   else if(winner == COMPUTER)
   {
      cout << "YOU LOSE!";
   }
   else
   {
      cout << "IT'S A TIE!";
   }
}

