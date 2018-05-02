// Author: Sandeep Singh
// Date: May 2, 2018
// Reference: 
// https://www.geeksforgeeks.org/print-a-given-matrix-in-spiral-form

#include <iostream>
using namespace std;
#define RowMax 3
#define ColMax 6

void printSpiral(int rowEnd, 
                 int colEnd, 
                 int a[RowMax][ColMax])
{
	int i, rowStart = 0, colStart = 0;

  	#if 0
	rowStart - starting row index  
	rowEnd - ending row index  
	colStart - starting column index 
	colEnd   - ending column index  
  	i - iterator 
 	#endif

	while (rowStart < rowEnd && colStart < colEnd)
	{
		// TOP ROW: 
		// row_no = rowStart [constant]
		// col_no = iterator [vary]
		for (i = colStart; i < colEnd; ++i)
		{
			cout << a[rowStart][i] << " ";
		}
		rowStart++;

		// RIGHT COLUMN: 
		// row_no = iterator [vary]
		// col_no = colEnd-1 [constant]
		for (i = rowStart; i < rowEnd; ++i)
		{
			cout << a[i][colEnd-1] << " ";
		}
		colEnd--;

		// BOTTOM ROW:
		// row_no = rowEnd-1 [constant]
		// col_no = reverse-iterator [vary] 
		if ( rowStart < rowEnd)
		{
			for (i = colEnd-1; i >= colStart; --i)
			{
				cout << a[rowEnd-1][i] << " ";
			}
			rowEnd--;
		}

		// LEFT COLUMN:
		// row_no = reverse-iterator [vary]
		// col_no = colStart [constant]
		if (colStart < colEnd)
		{
			for (i = rowEnd-1; i >= rowStart; --i)
			{
				cout <<  a[i][colStart] << " ";
			}
			colStart++; 
		}	
		cout << endl;
	}
}

// Driver Program for Testing
int main()
{
	int a[RowMax][ColMax] = { {1, 2, 3, 4, 5, 6},
		                  {7, 8, 9, 10, 11, 12},
		                  {13, 14, 15, 16, 17, 18}
	                        };

	printSpiral(RowMax, ColMax, a);
	return 0;
}
