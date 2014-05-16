// Khamille A. Sarmiento
// CS 265 - C++ Programming
// Prof. Raheja
// Project 3.1 Polynomial Ops

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>
#include "Polynomial.h"
using namespace std;

// Counts how many instances of 'x' occurs in the polynomial.
int numOfTerms(string polynomial) {
	int counter = 0;
	int poly_size = polynomial.length();
	for(int i = 0; i < poly_size; i++) {
		if(polynomial[i] == 'x') {
			counter ++;
		}
	}
	return counter;
}

int main() {

	string polyString_1; 
	string polyString_2;
	int n, m; // Number of terms for each polynomial
	int option  = 0;

	cout << "// POLY ME: A polynomial calculator from the 1993.  \n\n\n";

	cout << "// How to use: When entering polynomials, you must use the form,\n";
	cout << "// Cx^y + Cx^y + ... where C = coefficient and y = exponent. Mathematically, \n";
	cout << "// an equation is no longer a polynomial if one of its its powers is negative, \n";
	cout << "// therefore this program does not properly evaluate negative exponents. \n";
	cout << "// PLEASE NOTE! When entering constants, please use the form Cx^0; where \n";
	cout << "// x^0 = 1. \n\n\n";

	
	cout << "// POLYNOMIAL 1: ";
	getline(cin, polyString_1);
	n = numOfTerms(polyString_1);
	Polynomial firstPolynomial(n);
	firstPolynomial.set(polyString_1);

	cout << "// POLYNOMIAL 2: ";
	getline(cin, polyString_2);
	m = numOfTerms(polyString_2);
	Polynomial secondPolynomial(m);
	secondPolynomial.set(polyString_2); 

	//polyString_1 = "-4x^0 + 1x^1 + 2x^2";
	//polyString_2 = "5x^0 + 1x^1 - 2x^4";
	//
	//n = numOfTerms(polyString_1);
	//Polynomial firstPolynomial(n);
	//firstPolynomial.set(polyString_1);
	//		
	//m = numOfTerms(polyString_2);
	//Polynomial secondPolynomial(m);
	//secondPolynomial.set(polyString_2);

	do {

		system("cls");
		cout << "\n// POLYNOMIAL 1: ";
		firstPolynomial.get();

		cout << "// POLYNOMIAL 2: ";
		secondPolynomial.get();

		cout << "\n// MENU\n";

		cout << "// ADD ME: Type 1 and hit 'Enter' \n";
		cout << "// SUBTRACT ME: Type 2 and hit 'Enter' \n";
		cout << "// MULTIPLY ME: Type 3 and hit 'Enter' \n";
		cout << "// ASSIGN ME: Type 4 and hit 'Enter' \n";
		cout << "// EXIT: Type 5 and hit 'Enter' \n\n";

		cout << "// YOUR RESPONSE: ";
		cin >> option;
		

		Polynomial result;
		if(option == 1) { // Addition option.
			system("cls");
			cout << "\n// ADDITION: Simple polynomial addition that adds like terms. \n\n";

			cout << "// POLYNOMIAL 1: ";
			firstPolynomial.get();
			cout << "// POLYNOMIAL 2: ";
			secondPolynomial.get();

			cout << "\n// RESULT : ";
			result = firstPolynomial + secondPolynomial;
			result.get();

		} 
		else if(option == 2) {
			system("cls");
			cout << "\n// SUBTRACTION: Simple polynomial subtraction that subtracts like terms. \n\n";

			cout << "// POLYNOMIAL 1: ";
			firstPolynomial.get();
			cout << "// POLYNOMIAL 2: ";
			secondPolynomial.get();

			cout << "\n// RESULT : ";
			result = firstPolynomial - secondPolynomial;
			result.get();
		} 
		else if(option == 3) {
			system("cls");
			cout << "\n// MULTIPLICATION: Uses the mathematical method called 'FOIL.' \n\n";

			cout << "// POLYNOMIAL 1: ";
			firstPolynomial.get();
			cout << "// POLYNOMIAL 2: ";
			secondPolynomial.get();

			cout << "\n// RESULT: ";
			result = firstPolynomial * secondPolynomial;
			result.get();
		} 
		else if(option == 4) {
			system("cls");
			int assignmentOption = 0;
			do {
			
				cout << "\n// POLYNOMIAL 1: ";
				firstPolynomial.get();
				cout << "// POLYNOMIAL 2: ";
				secondPolynomial.get();

				cout << "\n// ASSIGNMENT MENU \n\n";

				cout << "// CHANGE POLY 1: Type 1 and hit 'Enter' \n";

				cout << "// CHANGE POLY 2: Type 2 and hit 'Enter' \n\n";

				cout << "// YOUR RESPONSE: ";
				cin >> assignmentOption;


				if(assignmentOption == 1) {
					system("cls");
					string newString = "";
					cout << "\n// POLYNOMIAL 1: ";
					cin.ignore();
					getline(cin, newString);
					n = numOfTerms(newString);
					Polynomial newPolynomial(n);
					newPolynomial.set(newString);
					firstPolynomial = newPolynomial;

					system("cls");
					cout << "\n// YOUR NEW POLYNOMIAL 1: ";
					firstPolynomial.get();
				}

				else if(assignmentOption == 2) {
					system("cls");
					string newString = "";
					cout << "\n// POLYNOMIAL 2: ";
					cin.ignore();
					getline(cin, newString);
					m = numOfTerms(newString);
					Polynomial newPolynomial(m);
					newPolynomial.set(newString);
					secondPolynomial = newPolynomial;

					system("cls");
					cout << "\n// YOUR NEW POLYNOMIAL 2: ";
					secondPolynomial.get();
				}

				else {
					system("cls");
					cout << "You did not select a valid option. \n";
				} 

				cout << endl;

			} while(assignmentOption != 1 && assignmentOption != 2);
		} 
		else if(option == 5) {
			system("cls");
			cout << "\n// POLY ME: A polynomial calculator from the 1993.  \n";
			cout << "\nThank you for using POLY ME. Goodbye. \n";
			exit(1);

		} 
		else {
			system("cls");
			cout << "You did not select a valid option. \n";
		} 

		cout << "\n" << endl;
		system("pause");
 
	} while(option != 5);

	return 0;
}