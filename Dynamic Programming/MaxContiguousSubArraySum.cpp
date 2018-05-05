// Author: Sandeep Singh
// Date: May 5, 2018
// File: MaxContiguousSubArraySum.cpp
// Description: Find Maximum Sum for a contiguous sub-array
// Reference: https://www.geeksforgeeks.org/largest-sum-contiguous-subarray

#include<iostream>
using namespace std;

int maxContiguousSubArraySum(int array[], 
                          int size)
{
    int max_so_far = array[0];
    int curr_max   = array[0];

    for (int i = 1; i < size; i++)
    {
        // If current element = +ve, add it to curr_max (increase)    
        //                    =   0, curr_max remains unaffected, keep moving
        //                    = -ve, curr_max would be decreased -- but max_so_far = Unaffected
    		curr_max   = max (array[i], 
    		                  curr_max + array[i]);
    		                  
    		max_so_far = max (max_so_far, 
    		                  curr_max);
    }
    
    return max_so_far;
}

// Driver Program for Testing
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    
    int max_sum = maxContiguousSubArraySum(a, n);
    
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
