#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void findSeddlePoint(int i,	int min, int array[4][4], 
	int const kRow, int const kCol);

int main()
{
	int i, j, min, max, sum;
	int const kRow = 4, kCol = 4;

	int array[kRow][kCol];
	ifstream fin("array.txt");
	if (!fin.is_open())
	{
		cout << "can't open file" << endl;
		return 1;
	}
	for (int i = 0; i < kRow; i++){
		for (int j = 0; j < kCol; j++)
		{
			fin >> array[i][j];
			cout << setw(3) << array[i][j] << setw(2) << "|";
		}
	cout << endl;
    }

	for (i = 0; i < kRow; i++) {
		for (j = 0; j < kCol; j++)
			if (array[i][j] < 0)
			{
				sum = 0;
				for (j = 0; j < kCol; j++)
					sum += array[i][j];
				cout << "Sum=" << sum << endl;
				break;
			}
	}
	
	for (i = 0; i < kRow; i++)
	{
		min = array[i][0];
	    findSeddlePoint(i, min, array, kRow, kCol);
	}

	return 0;
}

void findSeddlePoint(int i, int min,
	int array[4][4], int const kRow, int const kCol) {
	int i_row_min = i;
	int j_col_min = 0;
	int i_row_max = i;

	for (int j = 0; j < kCol; j++)
	{
		if (array[i][j] < min)
		{
			min = array[i][j];
			i_row_min = i;
			j_col_min = j;
		}
	}
 check:
	int max = min;
	for (i = 0; i < kRow; i++)
		if (array[i][j_col_min] > max)
		{
			max = array[i][j_col_min];
			i_row_max = i;
		}

	if (i_row_min == i_row_max)
		cout << "Seddle point: " << max 
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