#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
	bool linearIn(int *outer, int *inner, int outerLen, int innerLen);
	int countTriple(string str);
	bool groupSum(int start, vector<int> nums, int target);
	bool googleSum(vector<int> nums, int sum);


	int outerArray[] = {1, 2, 4, 4, 6};
	int innerArray[] = {2, 3, 4};
	int outerSize = sizeof(outerArray)/sizeof(outerArray[0]);
	int innerSize = sizeof(innerArray)/sizeof(innerArray[0]);
	cout << linearIn(outerArray, innerArray, outerSize, innerSize) << endl; // prints

	string tripleString = "xxxabyyyycd";
	cout << countTriple(tripleString) << endl;


	int start = 0;
	vector<int> vec{2, 4, 8};
	int target = 13;
	cout << groupSum(start, vec, target) << endl;


	vector<int> nums{1,2,4,4};
	int sum = 7;
	cout << googleSum(nums, sum) << endl;


	return 0;
}


/*
 * Given two arrays of ints sorted in increasing order, outer and inner
 * , return true if all of the numbers in inner appear in outer.
 * The best solution makes only a single "linear" pass of both arrays,
 *  taking advantage of the fact that both arrays are already in sorted order.

linearIn([1, 2, 4, 6], [2, 4]) → true
linearIn([1, 2, 4, 6], [2, 3, 4]) → false
linearIn([1, 2, 4, 4, 6], [2, 4]) → true
 */

bool linearIn(int outer[], int inner[], int outerLen, int innerLen)
{
  int outerIndex = 0;
  int trueCounter = 0;
  for(int i=0;i<innerLen;i++)
  {
    while(outerIndex < outerLen)
    {
      if(outer[outerIndex] == inner[i])
      {
        trueCounter++;
        break;
      }
      outerIndex++;
    }
  }

  return(trueCounter==innerLen);
}


/*
 * We'll say that a "triple" in a string is a char
 * appearing three times in a row. Return the number of triples
 *  in the given string. The triples may overlap.

countTriple("abcXXXabc") → 1
countTriple("xxxabyyyycd") → 3
countTriple("a") → 0
 */

int countTriple(string str)
{
  int tripleCount = 0;
  for(int i=0;i<str.length();i++)
  {
    char currentChar = str[i];
    int j = 0;
    while(currentChar==str[i+j])
    {
      j++;
      if(j==3)
      {
        tripleCount++;
        break;
      }
      if(i+j>=str.length())
      {
        break;
      }
    }
  }
  return tripleCount;
}

/*
 * Given an array of ints, is it possible to choose a group
 * of some of the ints, such that the group sums to the given target?
 * This is a classic backtracking recursion problem. Once you understand the recursive
 * backtracking strategy in this problem, you can use the same pattern for many problems
 * to search a space of choices. Rather than looking at the whole array, our convention
 * is to consider the part of the array starting at index start and continuing to the
 * end of the array. The caller can specify the whole array simply by passing start as 0
 * No loops are needed -- the recursive calls progress down the array.

groupSum(0, [2, 4, 8], 10) → true
groupSum(0, [2, 4, 8], 14) → true
groupSum(0, [2, 4, 8], 9) → false
 */

bool groupSum(int start, vector<int> nums, int target)
{

 if(start>=nums.size())
 {
   if(target==0)
   {
     return true;
   }
   return false;
 }

 int currentNumber = nums[start];

 if(target==currentNumber)
 {
   return true;
 }

  return groupSum(start+1,nums,target) || groupSum(start+1,nums,target-currentNumber);
}


/*
 * Given an array of integers return if the sum of any two number equals the target sum.
 * The numbers are sorted and the best solution is linear O(n)
 * googleSum([1,2,3,9],8)  → false
 *  googleSum([1,2,4,4],8)  → true
 *
 */

bool googleSum(const vector<int> nums, int sum)
{
	int low = 0;
	int high = nums.size() - 1;
	while(low < high)
	{
		int s = nums[low] + nums[high];
		if(s==sum)
		{
			return true;
		}
		else if(s < sum)
		{
			low++;
		}
		else
		{
			high--;
		}
	}
	return false;
}

