// Author: Sandeep Singh
// Date: May 4, 2018
// File: LongestCommonPrefix.cpp
// Reference: https://www.geeksforgeeks.org/longest-common-prefix-set-4-binary-search

#if 0 
Given: A Set of Strings 

       geekysandeep
       geeks
       geek 
       geezer 

Required:
Longest Common Prefix = ?

Here:
       "geek"ysandeep
       "geek"s
       "geek" 
       "gee"zer
       
Longest Common Prefix = "gee" 
#endif
#include<bits/stdc++.h>
using namespace std;

// Out of all given Strings, find the one with Minimum length
// Note: Length of Longest Common Prefix <= Length of Shortest String of the Set
int findMinLength(string array[], 
                  int size)
{
	int min = INT_MAX;

	for (int i=0; i<size; i++)
	{
	    // Length of ith string = array[i].length() 
	    if (array[i].length() < min)
	        min = array[i].length();
	}
	
	return min;
}

bool doAllContainPrefix ( string array[],   // Input Set of Strings
                          int numbStrings,  // No. of Input in this Set
                          string prefix,    // Prefix -- to search in this Set between [start, end]
		          int start,        // Start Index (for all Strings) -- to be searched for Prefix
		          int end )         // End Index (for all Strings) -- to be searched for Prefix
{
	for (int i=0; i<=numbStrings-1; i++)
	{
	    for (int j=start; j<=end; j++)
	    {
	        if (array[i][j] != prefix[j])   // Match jth string character of ith string -- with Prefix Character
		return false;
	    }
	}
	return (true);
}

string findLongestCommonPrefix(string array[],    // Input Set of Strings
                               int size)          // No. of Input in this Set
{
	// Step-1: Find the Length of Shortest String in the Input Set 
	// Lenght of Longest Common Prefix <= Length of Shortest String of the Set
	int maxPrefixLength = findMinLength (array, 
	                                     size);
	
	// Resulting LCP String
	string longestCommonPrefix; 

    	// Step-2: Input Range for Binary Search on Input Set of Strings
	int low  = 0; 
	int high = maxPrefixLength;

    	// Step-3: Binary Search on Each String of Input Set from lenght=low to length-high
    	//         LCP string cannot be greater than maxPrefixLength
    	//         So, there is no point in searching any input string beyond index=maxPrefixLength-1
	while (low <= high)
	{
        	// Step-4: Find Mid-Point for Binary Search 
		int mid = low + (high - low) / 2;

        	// Step-5: [Key-Idea] 
       		//         Check if all Input Strings have a common prefix from length: [low, high]
        	//         Note: We are NOT searching the ENTIRE Prefix from [low, high] in one pass 
		//								   -- that's why it's Binary Search
        	//               We start from first half: [low, mid] 
        	//                  -- if it matches (for ALL) -- add common part to prefix 
		//					              & search from [mid+1, high] also in all Strings 
        	//                  -- if match failed -- Carry out next search in [low, mid-1] -- using new mid 
		if (doAllContainPrefix ( array, 
		                         size, 
		                         array[0],    // Using first String from Input as a reference (anyone can be used)  
		                                      // b'coz we are searching for common part in ALL Strings 
		                         low, 
		                         mid))
		{
		    	// Step-6: All Input Strings contain the prefix from [low, mid], so add prefix to LCP string
			longestCommonPrefix = longestCommonPrefix + array[0].substr(low, mid-low+1);

			// Step-7: After successful match from [low, mid] in all Input Strings,
			//         now its time to search for prefix from [mid+1, high] again - in all Input Strings
			low = mid + 1;
		}
        
        	// Step-8: Search for Prefix in the range [low, mid] failed
        	//         So, LCP must be shorter than [low, mid]
        	//         There is NO Point of searching the remaining half prefix -- from [mid+1, high]
        	// Repeat this procedure in the Left part of Prefix: [low, mid] by breaking it into 2 parts again
        	//        & then calculating the fresh mid
		else 
			high = mid - 1;
	}

	return longestCommonPrefix;
}

// Driver program for testing
int main()
{
	string array[] = {"geekysandeep", 
	                  "geeks",
			  "geek", 
			  "geezer"};
					
	int numb_strings = sizeof (array) / sizeof (array[0]);

	string lcp = findLongestCommonPrefix (array, numb_strings);

	if (lcp.length())
		cout << "Longest Common Prefix: " << lcp;
	else
		cout << "No Longest Common Prefix";
	return (0);
}
