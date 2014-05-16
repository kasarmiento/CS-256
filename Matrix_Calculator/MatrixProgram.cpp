// Khamille A. Sarmiento
// C++ Programming
// Project 2.2 - Matrix Multiplication

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int** createArray(int, int); // Used for manually-inputed matrix creation.
void print(int**, int, int); // Prints out any matrix given it's dimensions.
bool checkSameDimensions(int, int, int, int); // Can use for Matrix Addition or Subtraction.
bool checkMultDimensions(int, int, int, int); // Can use for Matrix Multiplication.
int** add(int**, int**, int, int); // Adds two matrices together if correct dimensions.
int** subtract(int**, int**, int, int); // Subtracts two matrices together if correct dimensions.
int** multiply(int**, int**, int, int, int, int); // Multiplies two matrices together if correct dimensions.
int** transpose(int**, int, int); // Transposes any matrix.



int main() {

	int** Matrix_A;
	int** Matrix_B;
	int** result;

	int arows; // Number of rows for Matrix A
	int acols; // Number of columns for Matrix A
	int brows; // Number of rows for Matrix B
	int bcols; // Number of columns for Matrix B

	cout << "\n===== MATRIX CALCULATOR 9000 ====\n";
	cout << "\n1. Read from file\n2. Manually Input\n";
	cout << "\n: ";

	int inputMethod;
	cin >> inputMethod;

	if(inputMethod == 1) { // Option 1: Read numbers from a file.

		system("cls");
		cout << "\n===== MATRIX CREATION ====\n";

		ifstream toRead;
		string filename;

		cout << "\nPlease enter the file name: ";
		cin >> filename;
		toRead.open(filename.c_str());

		if(toRead.is_open()) {
			toRead >> arows >> acols; // Receive dimensions for Matrix A.

			// Create a new matrix.
			int** arr_ptr_A = new int*[arows]; 
			for(int i = 0; i < arows; i++) { 
				*(arr_ptr_A + i) = new int[acols]; 
			}

			// Fill the first matrix with data from the file.
			for(int i = 0; i < arows; i++) {
				for(int j = 0; j < acols; j++) {
					int temp;
					toRead >> temp;
					*(*(arr_ptr_A + i) + j) = temp;
				}
			}

			Matrix_A = arr_ptr_A;
			cout << "Array A filled.\n";


			toRead >> brows >> bcols; // Receive dimensions for Matrix B.

			// Create a new matrix.
			int** arr_ptr_B = new int*[brows];
			for(int i = 0; i < brows; i++) { 
				*(arr_ptr_B + i) = new int[bcols];  
			}

			// Fill the next matrix with data from the file.
			for(int i = 0; i < brows; i++) {
				for(int j = 0; j < bcols; j++) {
					int temp;
					toRead >> temp;
					*(*(arr_ptr_B + i) + j) = temp;
				}
			}
			Matrix_B = arr_ptr_B;
			cout << "Array B filled.\n";
		}
		else {
			cout << "Error opening the file. Program will terminate.\n";
			exit(1);
		}

		
	} else if(inputMethod == 2) { // Option 2: Manually Input Matrix Values.
		system("cls");
		cout << "\n===== MATRIX CREATION =====\n\n";

		cout << "===== Matrix A =====\n\nrows: ";
		cin >> arows;
		cout << "columns: ";
		cin >> acols;
		cout << endl;

		Matrix_A = createArray(arows, acols);

		cout << "\n===== Matrix B =====\n\nrows: ";
		cin >> brows;
		cout << "columns: ";
		cin >> bcols;
		cout << endl;

		Matrix_B = createArray(brows, bcols);


	} else {
		cout << "You did not select 1 or 2. Program will terminate.\n";
		exit(1);
	}

	int desiredOperation = 0;

	do {

		system("cls");

		cout << "\n===== Matrix A ===== \n";
		print(Matrix_A, arows, acols);

		cout << "\n===== Matrix B ===== \n";
		print(Matrix_B, brows, bcols);

		cout << "\n1. Addition: A + B\n2. Subtraction: A - B\n3. Multiplication: A * B\n4. Transpose A\n5. Transpose B\n6. Exit Program\n";
		cout << "\n: ";

		cin >> desiredOperation;

		// ================================ Matrix Addition ==================================
		if(desiredOperation == 1) { 
			system("cls");
			cout << "\n===== Matrix Addition: RESULT =====\n\n";
			bool proceedAdd = checkSameDimensions(arows, acols, brows, bcols); // Checks for valid Addition dimensions.
			if(proceedAdd == true) {
				result = add(Matrix_A, Matrix_B, arows, acols);
				print(result, arows, acols);
			} else {
				cout << "Could not add. Dimensions do not match! ";
			}
		}

		// =============================== Matrix Subtraction ================================
		else if(desiredOperation == 2) {

			system("cls");

			cout << "\n===== Matrix Subtraction: RESULT =====\n\n";
			bool proceedSub = checkSameDimensions(arows, acols, brows, bcols); // Checks for valid Subtraction dimensions.
			if (proceedSub == true) {
				result = subtract(Matrix_A, Matrix_B, arows, acols);
				print(result, arows, acols);
				cout << endl;

			} else {
				cout << "\nCould not subtract. Dimensions do not match! ";
			}
		}

		// ============================== Matrix Multiplication ==============================
		else if(desiredOperation == 3) {

			system("cls");

			cout << "\n===== Matrix Multiplication: RESULT =====\n\n";
			bool proceed = checkMultDimensions(arows, acols, brows, bcols); // Checks for valid Multiplication dimensions
			if(proceed == true) {
				result = multiply(Matrix_A, Matrix_B, arows, acols, brows, bcols);
				print(result, arows, bcols);
				cout << endl;

			} else {
				cout << "\nCannot multiply. Dimensions do not work!;";
			}
		}

		// =============================== Transpose Matrix A ================================
		else if(desiredOperation == 4) {

			system("cls");

			cout << "===== TRANSPOSE MATRIX A =====\n";
			Matrix_A = transpose(Matrix_A, arows, acols);
			int save = arows;
			arows = acols;
			acols = save;
			cout << endl;
			print(Matrix_A, arows, acols);

		}

		// =============================== Transpose Matrix B ================================
		else if(desiredOperation == 5) {

			system("cls");

			cout << "===== TRANSPOSE MATRIX B =====\n";
			Matrix_B = transpose(Matrix_B, brows, bcols);
			int save = brows;
			brows = bcols;
			bcols = save;
			cout << endl;
			print(Matrix_B, brows, bcols);

		}

		else if(desiredOperation == 6) {
			system("cls");
			cout << "\n===== MATRIX CALCULATOR 9000 ====\n";
			cout << "\nThank you for using Matrix Calculator 9000. Goodbye. \n";
			exit(1);
		}

		else {
			system("cls");
			cout << "You did not select a valid option. \n";
		}

		system("pause");

	} while(desiredOperation != 6);


	return 0;
}

int** createArray(int n, int m) {

	int** arr_ptr = new int*[n]; // Creates a new array of ints. I can use this pointer as if it's an array.

	for(int i = 0; i < n; i++) { 
		*(arr_ptr + i) = new int[m];  // Creates new arrays of size m (num of columns) in each index of arr_ptr
	}

	// Nested for-loop. Fills up the 2d array via user input.
	for(int i = 0; i < n; i++) {

		for(int j = 0; j < m; j++) {
			int nu;
			cout << "row " << i << ", col " << j << ": ";
			cin >> nu;
			*(*(arr_ptr + i) + j) = nu;
		}
	}

	return arr_ptr;
}


// Prints out the values of a specified matrix.
// Parameters: **array to be printed, number of rows, number of columns
void print(int** arr, int n, int m) {
	for(int i = 0; i < n; i++) { // Nested for loops that print out values.
		for(int j = 0; j < m; j++) {
			cout << *(*(arr + i) + j) << " ";
		}
		cout << "\n";
	}
}	

// Checks validity of dimensions for Matrix Addition or Subtraction.
// Returns TRUE if dimensions are the same.
// Returns FALSE if dimensions do not work.
bool checkSameDimensions(int A_rows, int A_cols, int B_rows, int B_cols) {
	bool isSame = false;
	if(A_rows == B_rows && A_cols == B_cols) {
		isSame = true;
	}
	return isSame;
}
	
// Checks validity of dimensions for Matrix Multiplication on Matrix A and B.
// Returns TRUE if dimensions are valid.
// Returns FALSE if dimensions will not work.
bool checkMultDimensions(int A_rows, int A_cols, int B_rows, int B_cols) {
	bool isValid = false;
	if(A_cols == B_rows) {
		isValid = true;
	}
	return isValid;
}

// Adds two matrices together. 
// Parameters: First **array, second **array, number of rows, number of columns  
int** add(int** A, int** B, int n, int m) {
	
	int** sum = new int*[n];        // Create a new array of pointers with n rows.
	for(int i = 0; i < n; i++) {    // Fill each index with an array of size m (columns).
		*(sum + i) = new int[m];
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			*(*(sum + i) + j) = *(*(A + i) + j) + *(*(B + i) + j);
		}
	}
	return sum;
}

// Subtracts two matrices together. 
// Parameters: First **array, second **array, number of rows, number of columns  
int** subtract(int** A, int** B, int n, int m) {

	int** difference = new int*[n];   // Create a new array of pointers with n rows.
	for(int i = 0; i < n; i++) {     // Fill each index with an array of size m (columns).
		*(difference + i) = new int[m];
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			*(*(difference + i) + j) = (*(*(A + i) + j)) - (*(*(B + i) + j));
		}
	}
	return difference;
}

// Multiplies two matrices together. 
// Parameters: **array A, **array B, number of rows in A, 
// number of columns in A, number of rows in B, number of columns in B.
int** multiply(int** A, int** B, int an, int am, int bn, int bm) {

	// Goal: Product Matrix of size (an x bm), 
	// where Matrix A is (an x am) and Matrix B is (bn x bm)

	int** product = new int*[an];   // Create a new array of pointers with am number of rows.
	for(int i = 0; i < an; i++) {     // Fill each index with an array of size bn (columns).
		*(product + i) = new int[bm];
	}

	for(int i = 0; i < an; i++) {	
		for(int j = 0; j < bm; j++) {
			int save = 0; 
			for(int k = 0; k < am; k++) {
				save += (*(*(A + i) + k)) * (*(*(B + k) + j));	// Multiply correct matrix indexes and add the full row together.	
			}
			*(*(product + i) + j) = save; // Save to the correct matrix location.
		}
	}
	return product;

}

int** transpose(int** arr, int n, int m) {
	int newRows = m;
	int newCols = n;
	string data = "";
	int** transposed = new int*[newRows];   // Create a new array of pointers with m rows.
	for(int i = 0; i < newRows; i++) {     
		*(transposed + i) = new int[newCols];  // Fill each index with an array of size n (columns).
	}

	ofstream s;
	s.open("tmp.txt");
	for(int i = 0; i < n; i++) { // Nested for loops that append values to a string.
		for(int j = 0; j < m; j++) {
			s << (*(*(arr + i) + j)) << " ";
		}
	}
	s.close();

	ifstream r;
	r.open("tmp.txt");
	// Fill the first matrix with data from the file.
	for(int i = 0; i < newCols; i++) {
		for(int j = 0; j < newRows; j++) {
			int temp;
			r >> temp;
			*(*(transposed + j) + i) = temp;
		}

	}

	return transposed;

}