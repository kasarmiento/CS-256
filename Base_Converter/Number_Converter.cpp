// Khamille A. Sarmiento
// C++ Programming
// Project 2.3 - Number Converter

#include <iostream>
#include <string>
using namespace std;

bool check_full(int); // Checks if the stack is full.
bool check_empty(int); // Checks if the stack is empty.
void push(int*, int&, int); // Pushes new element onto the stack.
int pop(int*, int&); // Pops off an element from the stack.

int main() {

	int stack[100]; // Creates an array of size 100.
	int p = 0; // "Subscript value": Holds the value of next available spot on the stack.
	int deci; // Holds the decimal value to be converted.
	int userSelection;

	cout << "\n======= NERD NUMBER CONVERTER =======\n\n";
	cout << "\nPlease enter an integer to convert: ";
	cin >> deci;

	cout << "\n1. Convert " << deci << " to binary\n";
	cout << "2. Convert " << deci << " to octal\n";
	cout << "3. Convert " << deci << " to hexadecimal\n";

	cout << "\n: ";
	cin >> userSelection;


	cout << "\n";
	// CONVERT TO BINARY (base 2)
	if(userSelection == 1) {

		bool neg;
		if(deci < 0) { // Checks to see if user input is a negative value.
			neg = true;
			deci = deci * -1;
			cout << "(-"<< deci << ")sub10 = (-"; // Prints accordingly.
		}

		else {
			cout << "("<< deci << ")sub10 = (";
		}

		// Loops through and pushes the remainder onto the stack
		// until there is no more.
		while(deci != 0) {
			int remainder = deci % 2;
			deci = deci / 2;
			push(stack, p, remainder);
		}

		// Prints out values from the stack.
		while(check_empty(p) == false) {
			cout << pop(stack, p);
		}
		cout << ")sub2" << endl; 
		
	} 
	
	// CONVERT TO OCTAL (base 8)
	else if(userSelection == 2) {

		bool neg;
		if(deci < 0) { // Checks to see if user input is a negative value.
			neg = true;
			deci = deci * -1;
			cout << "(-"<< deci << ")sub10 = (-"; // Prints accordingly.
		}

		else {
			cout << "("<< deci << ")sub10 = (";
		}

		// Loops through and pushes the remainder onto the stack
		// until there is no more!
		while(deci != 0) {
			int remainder = deci % 8;
			deci = deci / 8;
			push(stack, p, remainder);
		}

		// Prints out values from the stack.
		while(check_empty(p) == false) {
			cout << pop(stack, p);
		}
		cout << ")sub8" << endl; 
	}

	// CONVERT TO HEXADECIMAL (base 16)
	else if(userSelection == 3) {

		bool neg;
		if(deci < 0) { // Checks to see if user input is a negative value.
			neg = true;
			deci = deci * -1;
			cout << "(-"<< deci << ")sub10 = (-"; // Prints accordingly. 
		}

		else {
			cout << "("<< deci << ")sub10 = (";
		}

		// Loops through and pushes the remainder onto the stack
		// until there is no more.
		while(deci != 0) {
			int remainder = deci % 16;
			deci = deci / 16;
			push(stack, p, remainder);
		}

		// Prints out values from the stack.
		// In hexadecimal, 10 = A, 11 = B, 12 = C,
		//                 13 = D, 14 = E, 15 = F
		while(check_empty(p) == false) {
			int toPrint = pop(stack, p);

			if(toPrint == 10) {
				cout << "A";
			} else if(toPrint == 11) {
				cout << "B";
			} else if(toPrint == 12) {
				cout << "C";
			} else if(toPrint == 13) {
				cout << "D";
			} else if(toPrint == 14) {
				cout << "E";
			} else if(toPrint == 15) {
				cout << "F";
			} else {
				cout << toPrint;
			}
		}
		cout << ")sub16" << endl; 
	}

	else {
		cout << "\nYou did not select a valid option. Program will terminate. \n";
	}
	
	cout << "\n";

	return 0;
}

// Checks to see if the stack is full by comparing 
// the current subscript value 'p' to the size of the stack.
// Parameter: subscript value of next available spot
bool check_full(int p) {
	if(p == 100) {
		return true;
	} else {
		return false;
	}
}

// Checks to see if the stack is empty by comparing 
// the current subscript value 'p' to 0 (the first index 
// of the stack).
// Parameter: subscript value of next available spot
bool check_empty(int p) {
	if(p == 0) {
		return true;
	} else {
		return false;
	}
}

// Adds a new element to the top of the stack. If the stack
// is full, the program will terminate.
//
// Alters the stack and updates the pointer through pass by reference.
// Parameters: stack array, subscript value, element to add.
void push(int* arr, int &p, int toAdd) {
	if(check_full(p) == true) {
		cout << "Error: The stack is full. Program will terminate. \n";
		exit(1);
	} else {
		*(arr + p) = toAdd; // Add element to array at index 'p'.
		p++; // Increment the subscript value to next open space.
	}
}

// Decrements the subscript value and prints out the last element
// in the stack. Similar to removing a value. If the stack is empty,
// there is no element to remove and program will terminate.
// 
// Alters the stack and updates the pointer through pass by reference.
// Parameters: stack array, subscript value.
// Returns: removed element.
int pop(int* arr, int &p) {
	if(check_empty(p) == true) {
		cout << "Error: The stack is empty. There is no element to remove.\n\nProgram will terminate. \n";
		exit(1);
	} else {
		p--; // Decrement subscript value to point to last element.
		return *(arr + p); // Returns "removed" value.
	}
}



