#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	int const kRow = 4, kCol = 4;

	int array[kRow][kCol];
	ifstream fin("array.txt");
	if (!fin.is_open())
	{
		cout << "can't open file" << endl;
		return 1;
	}

	for (int i = 0; i < kRow; i++)
	{
		for (int j = 0; j < kCol; j++)
		{
			fin >> array[i][j];
			cout << setw(3) << array[i][j] << setw(2) << "|";
		}
	   cout << endl;
    }

	for (int i = 0; i < kRow; i++) 
	{
		for (int j = 0; j < kCol; j++)
			if (array[i][j] < 0)
			{
				int sum = 0;
				for (j = 0; j < kCol; j++)
					sum += array[i][j];
				cout << "Sum=" << sum << endl;
				break;
			}
	}
	
	for (int k = 0; k < kRow; k++)
	{
		int min = array[k][0];
		int i_row_min = k;
		int j_col_min = 0;
		int i_row_max = k;

		for (int j = 0; j < kCol; j++)
		{
			if (array[k][j] < min)
			{
				min = array[k][j];
				i_row_min = k;
				j_col_min = j;
			}
		}
	check:
		int max = min;
		for (int i = 0; i < kRow; i++)
			if (array[i][j_col_min] > max)
			{
				max = array[i][j_col_min];
				i_row_max = i;
			}

		if (i_row_min == i_row_max)
			cout << "Saddle point: " << max
			<< "[" << i_row_min << "]"
			<< "[" << j_col_min << "]" << endl;

		for (int j = j_col_min + 1; j < kCol; j++)
		{
			if (array[i_row_min][j] == min)
			{
				min = array[i_row_min][j];
				i_row_max = i_row_min;
				j_col_min = j;

				goto check;
			}
		}
	}
	
	return 0;
}

