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

// Default Constructor.
// Sets size and counter to 0.
Polynomial::Polynomial() {
	coef = NULL;
	exp = NULL;
	size = 0;
	counter = 0;
}

// Overloaded Constructor.
// Accepts number of terms and dynamically allocates 
// memory for new arrays.
// Sets size to number of terms and counter to 0.
Polynomial::Polynomial(int n) {
	coef = new int[n];
	exp = new int[n];
	size = n;
	counter = 0;
}

// Copy Constructor.
// Accepts Polynomial to be copied and sets its
// values to be the same values as the new Polynomial.
Polynomial::Polynomial(const Polynomial& obj) {
	size = obj.size;
	counter = obj.counter;
	coef = new int[obj.size];
	exp = new int[obj.size];
	for(int i = 0; i < size; i++) {
		*(coef+i) = *(obj.coef+i);
		*(exp+i) = *(obj.exp+i);
	}
}


// Destructor. 
// Deletes the dynamically allocated coefficient 
// array and exponent array.
Polynomial::~Polynomial() {
	delete[] coef;
	delete[] exp;
}


// Set function.
// Sets a polynomial string into its corresponding coefficient
// and exponent arrays.
// Accepts Polynomial reference, polynomial string.
void Polynomial::set(string r) {
	// Initializations:
	int coefficient = 0;
	int exponent = 0;
	bool isNegative = false;
	bool isExponent = false;
	stringstream coef_stream;
	stringstream exp_stream;
	coef_stream.str("");
	exp_stream.str("");
	int stringSize = r.length();

	for(int i = 0; i <= stringSize; i++) {
		if(r[i] == '-') {
			if(isExponent == true) {
				exponent = atoi(exp_stream.str().c_str());
				coef[counter] = coefficient;
				exp[counter] = exponent;
				counter++;

				// Resets values for next term.
				coef_stream.str("");
				exp_stream.str("");
				isNegative = false;
				isExponent = false;
			}
			isNegative = true;
		}

		else if(r[i] == '+') {
			if(isExponent == true) {
				exponent = atoi(exp_stream.str().c_str());
				coef[counter] = coefficient;
				exp[counter] = exponent;
				counter++;

				// Resets values for next term.
				coef_stream.str("");
				exp_stream.str("");
				isNegative = false;
				isExponent = false;
			}
			isNegative = false;
		}

		else if(isdigit(r[i])) {
			if(isExponent == false) {
				coef_stream << r[i];
			}
			else {
				exp_stream << r[i];
			}
		}

		else if(r[i] == 'x') {
			if(isExponent == false) {
				if(isNegative == false) {
					coefficient = atoi(coef_stream.str().c_str());
				}
				else if(isNegative == true) {
					int temp = atoi(coef_stream.str().c_str());
					coefficient = temp * (-1);
				}
			}
		}
		else if(r[i] == '^') {
			isExponent = true;
		}
		else {
			if(isExponent == true) {
				exponent = atoi(exp_stream.str().c_str());
				coef[counter] = coefficient;
				exp[counter] = exponent;
				counter++;

				// Resets values for next term.
				coef_stream.str("");
				exp_stream.str("");
				isNegative = false;
				isExponent = false;
			}
		}
	}
}

// Get Function.
// Prints the polynomial that calls this method.
void Polynomial::get() {
	for(int i = 0; i < counter-1; i++) {
			cout << *(coef+i) << "x^" << *(exp+i) << " + "; 
	}
	int l = counter-1;
	cout << *(coef+l) << "x^" << *(exp+l) << endl;
}

// PolySort function. 
// Sorts the polynomial's arrays according to exponent values
// from least to greatest. 
void Polynomial::polySort() {
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size-1-i; j++) {
			if(exp[j] > exp[j+1]) {
				int exp_temp = exp[j];
				int coef_temp = exp[j];

				exp[j] = exp[j+1];
				coef[j] = coef[j+1];

				exp[j+1] = exp_temp;
				coef[j+1] = coef_temp;
			}
		}
	}
}

// "Combine Into Temp Function."
// Helper function used to combine a polynomial's arrays with 
// another's into a temporary Polynomial object. Used in the overloaded 
// (+) and (-) operator functions. 
// Accepts a reference to an already created temp Polynomial, and a reference
// to the other Polynomial object to combine. 
// NOTE: When adding new values into the temp object, DON'T FORGET to 
// increment its counter!
Polynomial Polynomial::combineIntoTemp(Polynomial& temp, const Polynomial& right) {
	for(int i = 0; i < size; i++) { // goes from 0 to size-1, used to fill temp array with left/current values
		*(temp.coef+i) = *(coef+i);
		*(temp.exp+i) = *(exp+i);
		temp.counter++;
	}
	for(int i = size; i < temp.size; i++) { // goes from size to temp.size-1, used to fill remaining temp array with right/adt'l values
		*(temp.coef+i) = *(right.coef+(i-size));
		*(temp.exp+i) = *(right.exp+(i-size));
		temp.counter++;
	}
	return temp;
}

// Check Matching Exponents Function.
// Counts how many like terms there are in a polynomial.
// Returns the number of like terms.
int Polynomial::checkMatchingExp(const Polynomial& temp) {
	int numOfLikeTerms = 0;
	for(int i = 0; i < temp.size; i++) {
		if( (i != 0) && ( *(temp.exp+i) == *(temp.exp+(i-1)) ) ) { // if not first, and if current exponent equals previous exponent
			numOfLikeTerms++;
		}
	}
	return numOfLikeTerms;
}

// Overloaded Addition Operator.
// 1. Creates a temporary polynomial object to hold contents of both the left
//    and right operands.
// 2. Sorts the temporary polynomial object by exponent, ascending order.
// 3. Creates a 'result' polynomial object to hold the sum.
// 4. Adds terms from temp polynomial object to the 'result' polynomial object, 
//    combining like terms in the process.
// 5. Returns the resulting polynomial object.
Polynomial Polynomial::operator+(const Polynomial& right) {
	Polynomial temp(size + right.size);
	combineIntoTemp(temp, right);
	temp.polySort();

	int numOfLikeTerms = temp.checkMatchingExp(temp);
	int resultSize = temp.size - numOfLikeTerms;
	Polynomial sum(resultSize);

	for(int i = 0; i < temp.size; i++) {
		if( (i == 0) || ( *(temp.exp+i) != *(temp.exp+(i-1))) ) {
			*(sum.coef+(sum.counter)) = *(temp.coef+i); 
			*(sum.exp+(sum.counter)) = *(temp.exp+i);
			sum.counter++;
		}
		else { // if not first, and if current exponent equals previous exponent
			*(sum.coef+(sum.counter-1)) += *(temp.coef+i);
		}
	}
	return sum;
}

// Overloaded Subtraction Operator.
// 1. Creates a temporary polynomial object to hold contents of both the left
//    and right operands.
// 2. Sorts the temporary polynomial object by exponent, ascending order.
// 3. Creates a 'result' polynomial object to hold the difference.
// 4. Copies terms from temp polynomial object to the 'result' polynomial object, 
//    subtracting like terms in the process.
// 5. Returns the resulting polynomial object.
Polynomial Polynomial::operator-(const Polynomial& right) {
	Polynomial temp(size + right.size);
	combineIntoTemp(temp, right);
	temp.polySort(); 

	int numOfLikeTerms = temp.checkMatchingExp(temp);
	int resultSize = temp.size - numOfLikeTerms;
	Polynomial difference(resultSize);

	for(int i = 0; i < temp.size; i++) {
		if( (i == 0) || ( *(temp.exp+i) != *(temp.exp+(i-1))) ) {
			*(difference.coef+(difference.counter)) = *(temp.coef+i); 
			*(difference.exp+(difference.counter)) = *(temp.exp+i);
			difference.counter++;
		}
		else { // if not first, and if current exponent equals previous exponent
			*(difference.coef+(difference.counter-1)) -= *(temp.coef+i);
		}
	}
	return difference;
}

// Overloaded Multiplication Operator.
// 1. Creates a temporary polynomial object to hold multiplied contents of both 
//    the left and right operands.
// 2. Sorts the temporary polynomial object by exponent, ascending order.
// 3. Creates a 'result' polynomial object to hold the product.
// 4. Copies terms from temp polynomial object to the 'result' polynomial object, 
//    subtracting like terms in the process.
// 5. Returns the resulting polynomial object.
Polynomial Polynomial::operator*(const Polynomial& right) {
	Polynomial temp(size * right.size);for(int i = 0; i < size; i++) {
		for(int j = 0; j < right.size; j++) {
			*(temp.coef+(temp.counter)) = (*(coef+i)) * (*(right.coef+j));
			*(temp.exp+(temp.counter)) = (*(exp+i)) + (*(right.exp+j));
			temp.counter++;
		}
	}
	temp.polySort();

	int numOfLikeTerms = temp.checkMatchingExp(temp);
	int resultSize = temp.size - numOfLikeTerms;
	Polynomial product(resultSize);

	for(int i = 0; i < temp.size; i++) {
		// if not first, OR if current exponent does NOT equal previous exponent
		if( (i == 0) || ( *(temp.exp+i) != *(temp.exp+(i-1))) ) {
			// simply place it into result.
			*(product.coef+(product.counter)) = *(temp.coef+i); 
			*(product.exp+(product.counter)) = *(temp.exp+i);
			product.counter++;
		}
		else { 
			*(product.coef+(product.counter-1)) += *(temp.coef+i);
		}
	}
	return product;
}
// Overloaded Assignment Operator.
// Changes the value of the polynomial object calling the operator to
// equal the value of the polynomial object on the right side of the equal
// sign.
// Returns 'this', a.k.a. the polynomial object that called the operator.
const Polynomial Polynomial::operator=(const Polynomial &right) {
	delete[] coef;
	delete[] exp;
	size = right.size;
	counter = right.counter;
	coef = new int[size];
	exp = new int[size];
	for(int i = 0; i < size; i++) {
		*(coef+i) = *(right.coef+i);
		*(exp+i) = *(right.exp+i);
	}
	return *this;
}