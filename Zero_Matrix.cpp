#include <iostream>
#include <string>
using namespace std;

/*
1.8 Zero Matrix: Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
column are set to 0

- save all the zero indexes in array, and then move forward the array,
and put zero at every row\column in the array.
O(N^2) + O(N) space
*/

#define ROWS 3
#define COL 3
 
void zeroRow(int row, int(&matrix)[ROWS][COL]);
void zeroCol(int col, int(&matrix)[ROWS][COL]);
void zeroMatrix(int (&matrix)[ROWS][COL]);

int main()
{
	int matrix[ROWS][COL] = { {1,2,3},{4,5,0},{6,7,8} };
	zeroMatrix(matrix);
	return 0;
}


void zeroMatrix(int (&matrix)[ROWS][COL])
{	
	int temp;
	vector<int> arr;

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (matrix[i][j] == 0)
			{
				arr.push_back(i); //row
				arr.push_back(j); //col
			}
		}
	}

	for (int k = 0; k < arr.size(); k+=2)
	{
		int row = arr[k];
		int col = arr[k + 1];
		
		zeroRow(row, matrix);
		zeroCol(col, matrix);
	}
}

void zeroRow(int row, int (&matrix)[ROWS][COL])
{
	for (int i = 0; i < ROWS; i++)
	{
		matrix[row][i] = 0;
	}
}

void zeroCol(int col, int(&matrix)[ROWS][COL])
{
	for (int i = 0; i < COL; i++)
	{
		matrix[i][col] = 0;
	}
}
