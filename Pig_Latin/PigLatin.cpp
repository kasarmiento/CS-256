// Khamille A. Sarmiento
// C++ Programming
// Project 2.1 - Pig Latin

#include <iostream>
#include <string>
using namespace std;

// Converts a word or phrase to pig latin while printing it. 
void convert(string);

int main() {

	// Used to hold the user's phrase to convert.
	string phrase;

	cout << "======= ENGLISH TO PIG LATIN TRANSLATOR 9000 =======\n";
	cout << "\nPlease enter your phrase: ";
	getline(cin, phrase);

	cout << "Your phrase in Pig Latin: ";
	convert(phrase);
	cout << "\n" << endl;

	return 0;
}

// Converts a word or phrase to pig latin while printing it. 
// Parameter: string to be converted.
void convert(string pig) {

	int ptr = 0; // Used to keep track of current position of string.
	char temp; // Used to save first letter of each word.

	for(int i = 0; i < pig.length(); i++) {
		
		if(isspace(pig[i])) { // Finds a space to denote the end of a word.
			temp = pig[ptr]; // Saves the first letter of the original word.
			for(int j = ptr + 1; j < i; j++) {
				cout << pig[j]; // Prints remaining letters until the end of word is reached.
			}
			cout << temp << "ay "; // Prints the first letter and "ay ".
			ptr = i + 1;  // Move pointer up to the next word
		}

		else if(i == pig.length()-1) { // For loop reaches the last word.
			temp = pig[ptr];
			for(int j = ptr + 1; j <= i; j++) {
				cout << pig[j];
			}
			cout << temp << "ay ";
			ptr = i + 1;
		}
	}
}