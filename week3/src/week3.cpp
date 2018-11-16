//============================================================================
// Name        : week3.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	// Funtion Prototypes
	int sum(int firstNumber, int secondNumber);
	void printVector(vector<int> vectorToPrint, int size);
	// Defines an empty array with 5 integer size
	int myArray[100];
	// Defines an array with 10,20,30 elements
	int numberArray[] = { 10, 20, 30 };
	// We can also define arrays as pointers, which I will cover in 4th week
	int *anotherArray = new int[5];

	// prints the first element of the array
	cout << numberArray[0] << endl;

	// we can insert a new element into an array like this
	numberArray[3] = 40;
	cout << numberArray[3] << endl;

	// Let's fill an array to play with
	for(int i=0;i<100;i++)
	{
		myArray[i] = i;
	}

	// Getting the size of array
	int arraySize = (sizeof(myArray)/sizeof(*myArray));

	for(int i=0;i<arraySize;i++)
	{
		cout << myArray[i] << endl;
	}

	cout << "-------------------------" << endl;
	// Removing an element from an array
	int arrayCursor = 0;
	int toRemove = 98;
	int removeCounter = 0;
	for(int i=0; i<arraySize; i++ ) {
	    if( myArray[i] != toRemove )
	    {
	    	myArray[arrayCursor++] = myArray[i];
	    }
	    else
	    {
	    	removeCounter++;
	    }
	}

	arraySize -= removeCounter;

	for(int i=0;i<arraySize;i++)
	{
		cout << myArray[i] << endl;
	}

	// Arrays are can be a little bit frustrating to deal with, in C++ we can use vectors instead
	std::vector<int> intVector(20);
	// Getting the size of vector
	int vectorSize = intVector.size();

	// Place some values in vector
	for(int i=0;i<vectorSize;i++)
	{
		intVector.at(i) = i;
	}

	cout << "-------------------------" << endl;


	for(int i=0;i<vectorSize;i++)
	{
		cout << intVector.at(i) << endl;
	}

	cout << "-------------------------" << endl;

	// Delete the second element
	intVector.erase(intVector.begin() + 1);
	vectorSize = intVector.size();
	for(int i=0;i<vectorSize;i++)
	{
		cout << intVector.at(i) << endl;
	}

	cout << "-------------------------" << endl;

	// Delete between second and 6th element
	intVector.erase(intVector.begin() + 1, intVector.begin() + 5);
	vectorSize = intVector.size();
	for(int i=0;i<vectorSize;i++)
	{
		cout << intVector.at(i) << endl;
	}

	// Let's use some functions
	int number1, number2;
	cout << "Enter number 1: " << endl;
	cin >> number1;
	cout << "Enter number 2: " << endl;
	cin >> number2;

	cout << "Sum of " << number1 << " and " << number2 << " is " << sum(number1, number2) << endl;

	printVector(intVector, vectorSize);
	return 0;

}

// Functions
int sum(int firstNumber, int secondNumber)
{
	return firstNumber+secondNumber;
}

void printVector(vector<int> vectorToPrint, int size)
{
	cout << "--- PRINTING VECTOR ---" << endl;
	for(int i=0;i<size;i++)
	{
		cout << vectorToPrint.at(i) << endl;
	}
	cout << "-----------------------" << endl;
}
