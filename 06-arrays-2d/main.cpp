#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	int const kRow = 4, kCol = 5;

	int array[kRow][kCol];
	ifstream fin("array.txt");
	if (!fin.is_open())
	{
		cout << "can't open file array.txt " << endl;
		return 1;
	}

	for (int k = 0; k < kRow; k++)
	{
		for (int j = 0; j < kCol; j++)
		{
			fin >> array[k][j];
			cout << setw(3) << array[k][j] << setw(2) << "|";
		}
	   cout << endl;
    }

	for (int k = 0; k < kRow; k++) 
	{
		for (int j = 0; j < kCol; j++)
			if (array[k][j] < 0)
			{
				int sum = 0;
				for (j = 0; j < kCol; j++)
					sum += array[k][j];
				cout << "Sum=" << sum << endl;
				break;
			}
	}
	
	for (int i = 0; i < kRow; i++)
	{
		int row_min = array[i][0];
		int row_min_i = i;
		int row_min_j = 0;
		

		for (int j = 1; j < kCol; j++)
		{
			if (array[i][j] < row_min)
			{
				row_min = array[i][j];
				row_min_i = i;
				row_min_j = j;
			}
		}
	check:
		int col_max = row_min;
		int col_max_i = i;
		for (int k = 0; k < kRow; k++)
			if (array[k][row_min_j] > col_max)
			{
				col_max = array[k][row_min_j];
				col_max_i = k;
			}

		if (row_min_i == col_max_i)
			cout << "Saddle point: " << col_max
			<< "[" << row_min_i << "]"
			<< "[" << row_min_j << "]" << endl;

		for (int j = row_min_j + 1; j < kCol; j++)
		{
			if (array[row_min_i][j] == row_min)
			{
				col_max_i = row_min_i;
				row_min_j = j;

				goto check;
			}
		}
	}
	
	return 0;
}

