// Week -1
/*
- What is C++?
- Where do we use it?
- C++ vs other languages
- What is compiling?
- Compile and run errors
- Basic structure of a C++ program


*/

// Including necessary libraries
#include <iostream> // Standard input output library
#include <limits> // Library to get min, max values of variables
#include <cmath> // For math experssions
// #include <cstdio> // for getchar
using namespace std; // using namespace std to avoid std::cout

int main() {
	// Equivalent to cout << "Hello World" << endl; as we use namespace std
	std::cout << "Hello World" << std::endl;
	// Let's get used to variables
	int myInteger = 1; // I am an integer, I am 16bit and signed so I can be between -2^15-1 and 2^15
	float myFloat = 1.41241; // I am float, I can store up to 7 decimals
	double myDouble = 1.4124132213; // I am double, I can store up to 15 decimals
	cout << "The value of myInteger is " << myInteger << endl;
	myInteger = 2.99; // This is an integer it will round itself to the value before the decimals..
	cout << "The value of myInteger is " << myInteger << endl;

    cout << "Size of char: " << sizeof(char) << " byte" << endl;
    cout << "Size of int: " << sizeof(myInteger) << " bytes" << endl;
    cout << "Size of float: " << sizeof(myFloat) << " bytes" << endl;
    cout << "Size of double: " << sizeof(myDouble) << " bytes" << endl;

    // I don't need to write std:: here as we have included this before
    int imin = std::numeric_limits<int>::min(); // minimum value of integer
    int imax = std::numeric_limits<int>::max(); // maximum value of integer
    cout << "Minimum value of integer is: " << imin << endl;
    cout << "Maximum value of integer is: " << imax << endl;
    float fmin = std::numeric_limits<float>::min(); // minimum value of float
    float fmax = std::numeric_limits<float>::max(); // maximum value of float
    cout << "Minimum value of float is: " << fmin << endl;
    cout << "Maximum value of float is: " << fmax << endl;
    // Anyway you get the idea.

    // We also have unsigned variables which we commonly use in embedded programming to save space
    unsigned int myUnsignedInteger = 4;
	cout << "The value of my unsigned integer is " << myUnsignedInteger << endl;
	myUnsignedInteger = -5; // If we do this we start counting from the maximum unsigned integer value
	// So unsigned int a = -5 is equivalent to unsigned int a = MAX_UNSIGNED_INT - 5 + 1
	// +1 is because 0 equals to 0 not MAX_UNSIGNED_INT
	cout << "The value of my unsigned integer is " << myUnsignedInteger << endl;
	// And also maximum unsigned int value is 2^16-1
	cout << "Maximum value of unsigned int is: " << std::numeric_limits<unsigned int>::max() << endl;

	// Her are some of the basic math operators
	// + is for addition
	// - is for extraction
	// * is for multiplication
	// / is for division
	// % is the modulus operator, (12 % 5 = 2)
	int x = 5; // Define a variable x as an integer with value of 5
	float result; // Define our result as float
	result = (3*x+8)/2; // Solve the equation
	cout << "Result of the equation is: " << result << endl; // Oops it rounded the result below as x was integer
	result = ((float)(3*x + 8)) / 2; // if we make the statement float we can fix the rounding issue.
	cout << "Result of the equation is: " << result << endl;
	// Or we can define x as an integer as well
	float y = 5; // Please note that we cannot redefine x here so we use y instead
	result = (3*y+8)/2;
	cout << "Result of the equation is: " << result << endl;
	// To get the power of a number we use pow() function from the cmath or math.h library
	// Let's get an input from the user
	float number, power; // Define the variables first
	cout << "Please enter the number:\t"; // Kindly request an input ( \t is for tab, \n is for newline)
	cin >> number; // Pass the input to variables
	cout << "Please enter the power to be taken:\t";
	cin >> power;
	// Take the power of the passed variables
	cout << number << " to the power of " << power << " is " << pow(number,power) << endl;

	// If you cannot see your results in terminal just add this
	// getchar();


	// We need to write this to cleanly finish the program
	return 0;
}
