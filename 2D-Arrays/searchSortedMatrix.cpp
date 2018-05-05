// Author: Sandeep Singh
// Date: May 2, 2018
// Reference: https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix
#include <iostream>

using namespace std;

#if 0 
Input : 
key
a[4][4] = { {10, 20, 30, 40},
            {15, 25, 35, 45},
            {27, 29, 37, 48},
            {32, 33, 39, 50}};
            
(i) key = 29            
Output : 
Match Found: 2 1

(ii) key = 100
Output : No Match
#endif

void searchKey (int a[4][4], 
               int size, 
               int key)
{
    // Start Search with Top Right Element: a[0][size-1]
    int row = 0;
    int col = size-1; 
    
    while ( row <= size-1 && col >= 0 )
    {
	    if ( key == a[row][col] )
	    {
	    	cout << "Match Found: " <<  row << " " << col << endl;
		    return;
	    }
	    // Match in Same Row Possible, decrease the col
	    if ( key < a[row][col]) 
		    col--;
		// Key > Largest Row Entry, move to next row
	    else // key > a[i][j]
		    row++;
    }

    cout << "No Match" << endl;
}

// Driver Code for Testing
int main()
{
    int a[4][4] = { {10, 20, 30, 40},
				    {15, 25, 35, 45},
				    {27, 29, 37, 48},
				    {32, 33, 39, 50},
				};
				
	  int key = 29;
				
    searchKey(a, 4, key);
    return 0;
}
