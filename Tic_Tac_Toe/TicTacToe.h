// Khamille A. Sarmiento
// CS 265 - C++ Programming
// Prof. Raheja
// Project 3.2: Tic Tac Toe Game

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe { 
	private:
		static const int SIZE = 3;
		char **board;
	public:
		// Constructors.
		TicTacToe(); // Default constructor.
		TicTacToe(const TicTacToe&); // Copy constructor.
		~TicTacToe(); // Destructor.

		void set(char, int, int); // Places a player's mark into the board.
        void print(); // Prints out the game board.
        bool isMarked(int, int); // Returns a boolean value that tells whether a spot is already taken on the board.
        bool isFilled(); // Returns a boolean value that tells whether the board is full. 
		bool isWinner(); // Returns a boolean value that tells whether the board has a winner.
        
};

#endif