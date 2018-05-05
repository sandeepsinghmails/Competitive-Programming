// Author: Sandeep Singh
// Date: May 4, 2018
// File: SearchSortedRotatedArray.cpp
// Description: 
// Search an element in sorted and rotated array
// Reference: https://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array
#include <bits/stdc++.h>
using namespace std;

#define FAILURE -1

#if 0 
Given: A Sorted Array 
       1 2 3 4 5 6 7 8 9
     
       Now you rotate this array clockwise:
       9 1 2 3 4 5 6 7 8 
       
       If you keep rotating it unknown number of times:
       4 5 6 7 8 9 1 2 3

Required:
       Search for key in this rotated array

Key-Idea:
       - The rotated array contains 2 sorted sub-arrays
       - Either [low, mid] is Sorted or [mid+1, high] is Sorted
       
       Consider:
          1 2 3 4 5 6 7 8 9           (9 elements, mid = 4)
       
       => 7 8 9 1 [2] 3 4 5 6
       
       Here:
       [low, mid] is not sorted 
       But [mid+1, high] is still sorted -- even though we missed 1, 2 -- which should be part of (sorted) right sub-array
       
       Don't worry if your key was 1 or 2 -- we're not going to ignore these elements in search
       We will cover the case of {..., 1, 2, ..} in the failure case for search in right sub-array
#endif

// Returns:
// [Success]: Index of Matched key
// [Failure]: FAILURE
int binarySearch( int array[], 
                  int low, 
                  int high, 
                  int key)
{
        // Step-1: Base Case
	if (low > high) 
	    return FAILURE;

    	// Step-2: Calculate mid-index
	int mid = low + (high-low)/2;
	
	// Step-3: Match Mid-Index element with key
	if (array[mid] == key) 
	    return mid;

	// Step-4: Check if Left Subarray -- [low, mid] is sorted
	if (array[low] <= array[mid])
	{
	    	// Step-5: Check: Does key lies in Left Sorted Subarray
		if (key >= array[low] && key <= array[mid])
		{
		    // Step-6: Yes, key lies between [low, mid] which is Sorted
		    //         Like Normal Binary Search: Search again in [low, mid]
		    return binarySearch (array, low, mid-1, key);
		}

        	// Step-7: Failure Case for Left Subarray Search 
        	//         Key lies out of the range: [low, mid]
        	//         Search again in leftover range: [mid+1, high]
        	//         Note: Now we will break array[mid+1, high] into 2 subarrays by calculating new mid
		return binarySearch (array, mid+1, high, key);
	}

        // Step-8: As shown above if [low, mid] was NOT sorted, 
        //         [mid+1, high] would definitely be sorted -- even if we missed some elements from it (like: 1, 2)
    
        // Step-9: Check: Does key lies in Right Sorted Subarray
	if (key >= array[mid] && key <= array[high])
	{
	        // Step-10: Yes, key lies between [mid+1, high] which is Sorted
		//          Like Normal Binary Search: Search again in [mid+1, high]
		return binarySearch (array, mid+1, high, key);
	}
	
	// Step-11: Failure Case for Right Subarray Search 
    	//          Key lies out of the range: [mid+1, high]
    	//          Search again in leftover range: [mid+1, high]
    	//          Note: Now we will break array[mid+1, high] into 2 subarrays by calculating new mid
	return binarySearch (array, low, mid-1, key);
}

// Driver program for testing
int main()
{
	int array[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
	
	int n = sizeof(array)/sizeof(array[0]);
	
	int key = 6;
	int retVal = binarySearch (array, 0, n-1, key);

	if (FAILURE != retVal)
	    cout << "Match Found at Index: " << retVal << endl;
	else
	    cout << "No Match";
	
	return 0;
}
