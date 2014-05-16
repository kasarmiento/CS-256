// Khamille A. Sarmiento
// CS 265 - C++ Programming
// Prof. Raheja
// Project 3.1 Polynomial Ops

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

class Polynomial {
	private:
		int *coef; // Coefficient pointer used to dynamically allocate an array.
		int *exp; // Exponent pointer used to dynamicall allocate another array.
		int size; // Holds the size of the two arrays.
		int counter; // Used to keep track of next available spot in the arrays.

	public:
		Polynomial(); // Default constructor.
		Polynomial(int); // Overloaded constructor.
		Polynomial(const Polynomial&); // Copy constructor.
		~Polynomial(); // Destructor.

		void set(string); // Sets each term of the polynomial into their respective arrays. 
		void get(); // Prints the polynomial.

		// Helper functions. 
		Polynomial combineIntoTemp(Polynomial&, const Polynomial&); // Used to combine two Polynomial objects together
		void polySort(); // Sorts a polynomial's arrays in order from least to greatest.
		int checkMatchingExp(const Polynomial&); // Used to determine the number of like terms.

		//Overloaded functions. 
		Polynomial operator+(const Polynomial&);		
		Polynomial operator-(const Polynomial&);
		Polynomial operator*(const Polynomial&);
		const Polynomial operator=(const Polynomial&);
};

#endif