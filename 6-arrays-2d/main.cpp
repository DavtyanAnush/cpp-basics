#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

void findSeddlePoint(int i, int j,
	int min, int  max, int array[4][4], 
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
	for (int i = 0; i < kRow; i++) 
		for (int j = 0; j < kCol; j++) 
		{
			fin >> array[i][j];
		}

	
	for (i = 0; i < kRow; i++) {
		for (j = 0; j < kCol; j++)
		{
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

	
	for (j = 0; j < kCol; j++) {
		for (i = 0; i < kRow; i++)
		{
			min = array[i][j];
			max = min;
			findSeddlePoint(i, j, min, max, array, kRow, kCol);
		} cout << endl;
		break;
	}

	return 0;
}

void findSeddlePoint(int i, int j, int min, int  max, 
	int array[4][4], int const kRow, int const kCol) {
	int i_1 = i;
	int j_1 = j;
	int i_2 = i;
	for (j = 0; j < kCol; j++)
	{
		if (array[i][j] < min)
		{
			min = array[i][j];
			i_1 = i;
			j_1 = j;
		}
	}
check:
	max = min;
	for (i = 0; i < kRow; i++)
		if (array[i][j_1] > max)
		{
			max = array[i][j_1];
			i_2 = i;
		}
	if (i_1 == i_2)
		cout << "Seddle point: " << max 
		<< "[" << i_1 << "]" 
		<< "[" << j_1 << "]" << endl;

	i = i_1;
	for (j = j_1 + 1; j < kCol; j++)
	{

		if (array[i][j] == min)
		{
			min = array[i][j];
			i_1 = i;
			i_2 = i;
			j_1 = j;

			goto check;
		}
	}
}