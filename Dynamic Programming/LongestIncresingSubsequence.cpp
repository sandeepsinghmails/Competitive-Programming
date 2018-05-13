// Reference: https://www.geeksforgeeks.org/longest-increasing-subsequence

#include <iostream>
using namespace std;

int lis( int arr[], int size )
{
	int *lis;
	int curr, prev, maxLis = 0;
	
	// STEP-1: Create a DP Array -- to store lis value for each index [0 - n-1]
	lis =  new int [size];

	// STEP-2: Initialize LIS values for all indexes = min lis length = 1 (for current index string char)
	for (int i = 0; i < size; i++ )
	    lis[i] = 1;

	// STEP-3: Compute optimized LIS values in bottom up manner
	// Range of curr = [1, size-1] 
	// Exclude 0 bcoz you need to compare arr[curr] with arr [prev] where: prev<curr
	for (curr = 1; curr < size; curr++ )
	{
		for (prev = 0; prev < curr; prev++ ) 
		{
		    // [1] For Increasing Subsequence: arr[curr] > arr [prev]
		    // [2] For LONGEST Increasing Subsequence: 
		    //     lis[curr] = { max lis[prev] where prev=0 to curr-1 } + 1 (for string char at index=curr)
			if ( arr[curr] > arr[prev]      // [1]
			     && lis[curr] < lis[prev] + 1)    // [2]
				lis[curr] = lis[prev] + 1;
		}
	}

	// STEP-4: Find maximum of all LIS values 
	for (int i = 0; i < size; i++ )
	{
		if (maxLis < lis[i])
			maxLis = lis[i];
	}

	delete lis;

    // STEP-5: Length of Longest Increasing Subsequence
	return maxLis;
}

// Driver Test Function
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int size = sizeof(arr)/sizeof(arr[0]);
	
	cout << "Length of lis is: " << lis( arr, size ) << endl;
	
	return 0;
}
