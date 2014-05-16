// Khamille A. Sarmiento
// CS 265 - C++ Programming
// Prof. Raheja
// Project 3.2: Tic Tac Toe Game

#include <iostream>
#include <cstdlib>
#include <string>
#include "TicTacToe.h"
using namespace std;

int main() {
	char play;
	do {
		system("cls");
		cout << "// T I C - T A C - T O E //";
		cout << endl;
        
		const int SIZE = 3; // Size of the board.
		string player1; // String to hold name of Player 1.
		string player2; // String to hold name of Player 2.
		int row1, col1, row2, col2; // Int objects to hold subscripts of possible spaces.
		TicTacToe board; // TicTacToe object.

		cout << endl;

		// Gets the player's names.
		cout << "Player X, what is your name? ";
		getline(cin,player1);
		cout << "Player O, what is your name? ";
		getline(cin,player2);
		
		system("cls");
		cout << "// T I C - T A C - T O E //" << endl;
		cout << "\nWelcome " << player1 << "! Welcome " << player2 << "! \nWelcome to Tic Tac Toe!\n" << endl;
		system("pause");

		// Rules explained.
		system("cls");
		cout << "// T I C - T A C - T O E //" << endl;
		cout << "\nHere are the rules:\n\n";
		cout << "When it is your turn, type the space you'd like to place your \n";
		cout << "marker in this format: row column. Here's an example ==> 1 1 \n";
		cout << "Don't forget the space between your desired row and column! \n";
		cout << "Rows and columns only go from 1 to 3! Lastly, don't forget\n";
		cout << "to take turns! Okay, good luck!\n";
		cout << endl;
		system("pause");

		system("cls");

		cout << "// T I C - T A C - T O E //\n" << endl;
		board.print();
		cout << "\n" << endl;
		
		while(true) {
			cout << endl;
			// Player 1's turn.
			cout << player1 << "'s turn, what is your move? \n==> ";
			cin >> row1 >> col1;
			cout << endl;
			
			while (row1 > 3 || row1 < 1 || col1 > 3 || col1 < 1) { // Checks for valid row/col input.
				cout << "Invalid row and/or column. Please try again." << endl;
				cout << "\n" << player1 << "'s turn, what is your move? \n==> ";
				cin >> row1 >> col1;
				cout << endl;
			}
			while(board.isMarked(row1-1,col1-1) == true) { // Checks spot availability
                cout << "That spot is already taken. Please try again." << endl;
                cout << "\n" << player1 << "'s turn, what is your move? \n==> ";
                cin >> row1 >> col1;
                cout << endl;
            }
            board.set('x', row1-1, col1-1); // Sets player1's move onto the board.
            board.print(); 
      
            if(board.isWinner() == true) { // Checks if player 1 is a winner.
                cout << player1 << " wins!" << endl;
                break;
            } else if(board.isFilled() == true) { // If the board is full and there was no win, there was a tie.
                cout << "It's a tie!" << endl;
                break;
            }
            
            
            // Player 2's turn.
            cout << player2 << "'s turn, what is your move? \n==> ";
            cin >> row2 >> col2;
            cout << endl;
        
            while (row2 > 3 || row2 < 1 || col2 > 3 || col2 < 1 ) { // Checks for valid row/col input.
                cout << "Invalid row and/or column. Please try again." << endl;
                cout << "\n" << player2 << "'s turn, what is your move? \n==> ";
                cin >> row2 >> col2;
                cout << endl;
            }
			while (board.isMarked(row2-1, col2-1)) { // Checks spot availability.
                cout << "That spot is already taken. Please try again." << endl;
                cout << "\n" << player2 << "'s turn, what is your move? \n==> ";
                cin >> row2 >> col2;
                cout << endl;
            }
            board.set('o', row2-1, col2-1); // Sets player2's mark onto the board.
            board.print(); 
        
            if (board.isWinner()) { // Checks if player2 is a winner.
                cout << "Player 2 wins!" << endl;
                break;
            }    
        } // end game loop
		
		cout << "Play again (y/n)? \n==> ";
        cin >> play;
        
        while (play != 'n' && play != 'y') { // Loop if wrong response.
            cout << "Invalid answer. Please try again." << endl;
            cout << "Play again (y/n)? \n==> ";
            cin >> play;
        }
	} while (play == 'y');

	system("cls");
	cout << "// T I C - T A C - T O E //\n" << endl;
	cout << "Thank you for playing tic tac toe. Goodbye!" << endl;
    cout << endl;
    return 0;
}
