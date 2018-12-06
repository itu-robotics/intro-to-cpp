#include <iostream>
#include <cmath>
#include <Rover.h>

using namespace std;

int main() {
	bool hasOne(int n);
	void printArray(int *arrayoPrint, int size);
	int *squareUp(int n);

	Robot robot1(4,25); // wheels, weight
	Robot robot2(2,30);

	robot1.move(100);
	robot1.stop();
	cout << "Robot 1 has " << robot1.getNWheels() << " wheels and is " << robot1.getWeight() << " kg" << endl;

	robot2.setNWheels(4);
	robot2.setWeight(53.5);
	cout << "Robot 2 has " << robot2.getNWheels() << " wheels and is " << robot2.getWeight() << " kg" << endl;

	robot2.size[0] = 10;
	robot2.size[1] = 8;
	robot2.size[2] = 9;
	cout << "Robot 2's size is " << robot2.size[0] << "x" << robot2.size[1] << "x" << robot2.size[2] << endl;

	Rover rover1(6,50);
	cout << "This rover has " << rover1.getNWheels() << " wheels" << endl;
	rover1.robotArm = 6;
	rover1.moveArm();

	int number = 322;
	cout << "The number " << number << " returns " <<  hasOne(number) << endl;
	int n = 4;
	int *resultArray = squareUp(n);
	printArray(resultArray,pow(n,2));

	return 0;
}

/*
 * Question:

	Given a positive int n, return true if it contains the digit 1.

	hasOne(10) → true
	hasOne(22) → false
	hasOne(220) → false
*/

bool hasOne(int n)
{
	  if(n<10)
	  {
	    if(n==1)
	    {
	      return true;
	    }
	    return false;
	  }
	  if(n%10==1)
	  {
	    return true;
	  }
	  return hasOne(n/10);
}

/*
 * Question:
	Given n>=0, create an array length n*n with the following pattern,
	shown here for n=3 : {0, 0, 1,    0, 2, 1,    3, 2, 1} (spaces added to show the 3 groups).

	squareUp(3) → [0, 0, 1, 0, 2, 1, 3, 2, 1]
	squareUp(2) → [0, 1, 2, 1]
	squareUp(4) → [0, 0, 0, 1, 0, 0, 2, 1, 0, 3, 2, 1, 4, 3, 2, 1]
*/

int *squareUp(int n)
{
	  int *arr = new int[n*n];
	  int carry;
	  for(int i=0;i<n;i++)
	  {
	    carry = i+1;
	    int j = i*n;
	    int zeros = n - carry;
	    while(j<((i+1)*n))
	    {
	      if(zeros>0)
	      {
	        arr[j] = 0;
	        zeros--;
	      }
	      else
	      {
	        arr[j] = carry;
	        carry--;
	      }
	      j++;
	    }
	  }
	  return arr;
}

void printArray(int *arrayoPrint, int size)
{
	cout << "---- PRINTING ARRAY ----" << endl;
	int k = sqrt(size);
	for(int i=0;i<size;i++)
	{
		cout << arrayoPrint[i];
		if(i!=size-1)
		{
			cout << ",";
		}
		if((i+1)%k==0)
		{
			cout << "\t";
		}
	}
	cout << "\n-----------------------" << endl;
}
