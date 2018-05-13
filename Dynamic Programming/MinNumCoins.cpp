// Author: Sandeep Singh
// Date: May 5, 2018
// File: MinNumCoins.cpp
// Topic: Dynamic Programming
// Reference: https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change
#if 0 
Given: A Set of Coins 
       {9, 6, 5, 1}
       
       Amount of Change needed = Value (say, 11)
       
Required:
Minimum no. of Coins to sum up to Value = ?
#endif

#include<bits/stdc++.h>
using namespace std;

// m is size of coins array (number of different coins)
int findMinCoins ( int coinSet[], 
                   int numCoins, 
                   int Value)
{
	// minCoins [i] -- stores the Minimum Number of Coins required -- to sum up to Value=i
	// So, our required no. of coins would be = minCoins[Value]
	// Size of minCoins[] = Value+1 (since indexing starts from 0)
	int minCoins[Value+1];

	// Base case: To get Value = 0, min no of coins needed = 0
	minCoins[0] = 0;

	// Initialize all minCoins[] entries as Infinite -- which means Unknown
	for (int c=1; c<=Value; c++)
		minCoins[c] = INT_MAX;

        // Use: Memoization
	for (int v=1; v<=Value; v++)
	{
		/* To find out no. of minCoins which sum up to value 'v',
		 *    Consider Every Coin in Input Coin Set -- whose value <= v
		 */
		for (int c=0; c<numCoins; c++)
		{
			if (coinSet[c] <= v)
			{
			    // Key-Idea:
			    // Now, you have one coin: coinSet[c] having value <= v
			    // To reach v, remaining_sum = v-coinSet[c]
			    int remaining_sum = v-coinSet[c];

			    // Now, target: remaining_sum   --- This is your new Value
			    // How many minCoins sum up to Value=remaining_sum ?
			    // -- You've already calculated it :)
			    // => minCoins[Value=remaining_sum]
			    //    If this value is NOT Unknown (Infinite/INT_MAX) 
			    //    	minCoins required to sum up to Value (v) = 1 (for current coin: coinSet[c])
			    //							   + minCoins[remaining_sum]
			    //          Update: minCoins [v] = 1 + minCoins[remaining_sum]
			    if (minCoins[remaining_sum] != INT_MAX &&
				minCoins[remaining_sum] + 1 < minCoins[v])
				minCoins[v] = minCoins[remaining_sum] + 1;
			}
		}
	}
	return minCoins[Value];
}

// Driver program for Testing
int main()
{
	int coinSet[] = {9, 6, 5, 1};
	
	int numb = sizeof(coinSet)/sizeof(coinSet[0]);
	int V = 11;
	
	cout << "Minimum no. of Coins required -- to sum up to " << V << " is: "
		 << findMinCoins(coinSet, numb, V) << endl;
		
	return 0;
}
