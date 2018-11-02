//============================================================================
// Name        : week2.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


int main() {

	// if condition
	string name;
	cout << "Please enter your name: ";
	cin >> name;

	/* If the name equals Vatan the condition becomes true
	 * == is used for query, = is used for definition
	 * so below statement asks the question, "is the variable "name" equals to "Vatan"
	 * if the statement is true we get inside to if and print "Hello Vatan", if the statement is false
	 * we pass to next condition which is "is "name" equals "Sencer" and so on.
	 * If no condition defined inside if and else ifs is satisfied the program executes the else
	 */

	// Bool is another data type. It can be 0(false) or 1(true)
	bool isVatan = (name=="Vatan");
	cout << isVatan << endl;

	if(name == "Vatan")
	{
		cout << "Hello Vatan" << endl;
	}
	// If the name is not Vatan but Sencer
	else if(name == "Sencer")
	{
		cout << "Hello Sencer" << endl;
	}
	// Everything else
	else
	{
		cout << "I dont know you" << endl;
	}

	int number;
	cout << "Enter an integer here: ";
	cin >> number;

	// if the number is less than 0
	if(number < 0)
	{
		cout << "Your number is negative" << endl;
	}
	// if the number is not less than 0 and greater than 0
	else if (number > 0)
	{
		cout << "Your number is positive" << endl;
	}
	// Else the number is 0
	else
	{
		cout << "You entered 0" << endl;
	}

	/* Let's play with the number a little more
	 * && is the and operator
	 * So the condition will return true if number is less than or equal to 4
	 * and number is greater than or equal to 0.
	 */
	if(number <= 4 && number >= 0)
	{
		cout << "The number is between 0 and 4" << endl;
	}

	if(number != 2)
	{
		cout << "Your number is not 2" << endl;
	}
	else
	{
		cout << "Your number is 2" << endl;
	}

	int number1, number2;
	cout << "Enter number 1:";
	cin >> number1;
	cout << "Enter number 2:";
	cin >> number2;

	int op;
	cout << "Enter your operator 1 for +, 2 for -, 3 for /,4 for %,5 for * :";
	cin >> op;

	// Switch is pretty similar to if
	switch(op) 	// Use the operator as a key
	{
		// If the operator is 1
		case(1):
			cout << number1 << " plus " << number2 << " equals to " << number1+number2 << endl;
			break; // Break avoids the program to stuck in switch
		// If the operator is 2
		case(2):
			cout << number1 << " minus " << number2 << " equals to " << number1-number2 << endl;
			break;
		// Else
		default:
			cout << "Invalid operator, exiting..." << endl;

	}

	// For Loop
	// we define an integer i as 0
	// we execute the statement inside the loop
	// We increase the variable i by one
	// We check if i is still less than 5
	for(int i=0; i<5; i++)
	{
		cout << "This is loop number " << i << endl;
	}

	// While executes the statement inside the loop and checks if the condition is still satisfied
	int looper = 0;
	while(looper < 10)
	{
		looper += 1;
		cout << "Counting to 10... " << looper << endl;
	}
	// We can write the above loop as follows
	while(1) // Infinite loop <3
	{
		cout << "Infinite loop finishing in: " << looper << endl;
		looper--;
		if(looper == 0)
		{
			break;
		}
	}


	// Now let's write an easy calculator
	// Dark magic
	int endFlag = 0;
	while(1)
	{
		cout << "Enter your operator:\n 1 to +\n 2 to -\n 3 to /\n 4 to *\n 5 to %\n 6 to exit\n";
		cin >> op;
		cout << "Enter number 1:";
		cin >> number1;
		cout << "Enter number 2:";
		cin >> number2;

		switch(op)
		{
			case(1):
				cout << number1 << " plus " << number2 << " equals to " << number1+number2 << endl;
				break;
			case(2):
				cout << number1 << " minus " << number2 << " equals to " << number1-number2 << endl;
				break;
			case(3):
				cout << number1 << " over " << number2 << " equals to " << (float)number1/(float)number2 << endl;
				break;
			case(4):
				cout << number1 << " multiplied by " << number2 << " equals to " << number1*number2 << endl;
				break;
			case(5):
				cout << number1 << " mod " << number2 << " equals to " << number1%number2 << endl;
				break;
			case(6):
				cout << "Exiting" << endl;
				endFlag = 1;
				break;
			default:
				cout << "Invalid operator..." << endl;
				break;

		}
		// Dark magic commences
		if(endFlag)
		{
			break;
		}
	}

	return 0;
}
