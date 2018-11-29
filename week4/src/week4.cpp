#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	// Functions
	void towerOfHanoi(int numberOfDisks, char fromRod, char destRod, char extraRod);
	int *fillArray(int* arr, int numbersToFill);
	int addition (int a, int b);
	int subtraction (int a, int b);
	int operation (int x, int y, int (*functocall)(int,int));

	// Tower of Hanoi Solution
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods

    // ------------------------------------------------------------------------------------ //
	// Pointers ( Where we play with memories <3)
	// Define two Integers
	int firstValue, secondValue; // We now have addresses in memory for these variables
	// Define a pointer <3 <3 <3
	int *myPointer;

	// Pointer is just a cursor that points toward an address.
	// This can be any type from the data structures (int, double, char) or even arrays or vectors


	// We 'point' towards the address of the variable firstValue
	myPointer = &firstValue; // Care for the & sign, it is necessary for pointer operations
	*myPointer = 10; // We change the number in this address to 10
	myPointer = &secondValue; // We'point' towards the address of the variable secondValue
	*myPointer = 20; // We change the number in this address to 20
	cout << "firstValue is " << firstValue << '\n';
	cout << "secondValue is " << secondValue << '\n';


	// let's point an array and see different types of pointers usage
	int numbers[5]; // We define an array, called numbers
	int * p; // We define a pointer, p
	p = numbers;  *p = 10; // Point the beginning of the array
	p++;  *p = 20; // we move pointer by 1 character
	p = &numbers[2];  *p = 30; // We point to third integer of the array
	p = numbers + 3;  *p = 40; // We point the third integer from the beginning, which is the fourth
	p = numbers;  *(p+4) = 50; // We point the forth integer from the beginning, which is the fifth

	for(int i=0;i<5;i++)
	{
		cout << "Element number " << i << " of p is " << p[i] << endl;
	}

	// Normally we can't return arrays from function (but we can return vectors yay!)
	// USE VECTORS
	// USE VECTORS
	// USE VECTORS
	// But, we can use pointers to return C style arrays from functions
	int numbersToFill = 10;
	int myArray[numbersToFill];
	int *arrayToFill = fillArray(myArray, numbersToFill);

	for(int i=0;i<numbersToFill;i++)
	{
		cout << arrayToFill[i] << "\t";
	}

	// Pointers can also also point functions
	int a = operation(22,17, subtraction);
	cout << "\n\nResult of the operation is " << a << endl;

	// We can use pointers to point pointers to declare two dimensional Arrays
	cout << "\n ----------------------------POINTER TO POINTERS------------------------------ \n";

	int numberOfRows = 8; // We need to specify number of rows
	int numberOfColumns = 6; // And the number of columns
	int **pointer2D = new int*[numberOfRows]; // Declaring a pointer to a "numberOfRows" row array
	for(int i = 0; i < numberOfRows; ++i) {
		pointer2D[i] = new int[numberOfColumns]; // Adding "numberOfColumns" columns to every row
	}

	int i=0;
	int j=0;
	for(i=0;i<numberOfRows;i++)
	{
		for(j=0;j<numberOfColumns;j++)
		{
			pointer2D[i][j] = j+1;
			cout << pointer2D[i][j] << "\t";
		}
		cout << "\n";
	}

	// Then we need to clean up the mess we made to release memory
	for(int i = 0; i < numberOfRows; i++) {
	    delete [] pointer2D[i]; // Delete the 2D array
	}
	delete [] pointer2D; // Delete the last remaining pointer


	// It's easier in C style than pointers, but you need to know the pointer style as you may need to return 2d arrays
	cout << "\n ---------------------------- 2D ARRAY ------------------------------ \n";
	numberOfRows = 3;
	numberOfColumns = 4;
	int array2D[numberOfRows][numberOfColumns];

	for(i=0;i<numberOfRows;i++)
	{
		for(j=0;j<numberOfColumns;j++)
		{
			array2D[i][j] = j+1;
			cout << array2D[i][j] << "\t";
		}
		cout << "\n";
	}


	// We can also declare nested vectors for constructing 2D arrays.
	typedef vector<vector<int> > vector2d_t; // Typedef is a way of declaring a new data type
	// Now we have a new type of nested vectors called vector2d_t, we can use it like integers or strings etc.
	numberOfRows = 12;
	numberOfColumns = 8;

	vector2d_t vector2D(numberOfRows, vector<int>(numberOfColumns, 0));

	cout << "\n ---------------------------- 2D VECTOR ------------------------------ \n";
	for(i=0;i<numberOfRows;i++)
	{
		for(j=0;j<numberOfColumns;j++)
		{
			vector2D[i][j] = j+1;
			cout << vector2D[i][j] << "\t";
		}
		cout << "\n";
	}

	return 0;

}


// Function to solve tower of hanoi problem
void towerOfHanoi(int numberOfDisks, char fromRod, char destRod, char extraRod)
{
    if (numberOfDisks == 1)
    {
    	cout << "Move disk 1 from rod " << fromRod << " to rod " << destRod << endl;
        return;
    }
    // move all n-1 disks to extra rod
    towerOfHanoi(numberOfDisks-1, fromRod, extraRod, destRod);
    // Move nth disk to destination
    cout << "Move disk " << numberOfDisks << " from rod " << fromRod << " to rod " << destRod << endl;
    // Move n-1 disks from extra rod to destination
    towerOfHanoi(numberOfDisks-1, extraRod, destRod, fromRod);
}

// Function that fills a given 1D array
int *fillArray(int* arr, int numbersToFill)
{
	for(int i=0;i<numbersToFill;i++)
	{
		arr[i] = i;
	}
    return arr;
}


// A function to add two numbers
int addition (int a, int b)
{
	return (a+b);
}

// A function to subtract two numbers
int subtraction (int a, int b)
{
	return (a-b);
}

// A function that takes a function pointer as argument
int operation (int x, int y, int (*funcToCall)(int,int))
{
  return (*funcToCall)(x,y);
}


