#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

#define Row 4
#define Col 5

using namespace std;

template <class Type>
void readArr(Type array, string name) 
{
	ifstream fin(name + ".txt");
	if (!fin.is_open()) 
	{
		cout << "can't open file: "<< endl;
	}
	for (int i = 0; i < Row; i++) 
	{
		for (int j = 0; j < Col; j++) 
		{
			fin >> array[i][j];
		}
	}
	fin.close();
}

template <class Type>
void printArr(Type array) 
{
	cout << "Array: " << endl;
	for (int i = 0; i < Row; i++) 
	{
		cout << "|";
		for (int j = 0; j < Col; j++) 
		{
			cout << setw(5) << array[i][j] << setw(2) << "|";
		}
		cout << endl;
	}
	cout << endl << endl;
}

template <class Type>
void findSum(Type array) 
{
	int sum = 0;
	for (int k = 0; k < Row; k++)
	{
		for (int j = 0; j < Col; j++)
			if (array[k][j] < 0)
			{	
				sum = 0;
				for (j = 0; j < Col; j++)
					sum += array[k][j];
				cout << "Sum=" << sum << endl;
				break;
			}
	}
}

template <class Type>
void FaindSaddlePoint(Type array) 
{
	for (int i = 0; i < Row; i++)
	{
		int row_min = array[i][0];
		int row_min_i = i;
		int row_min_j = 0;


		for (int j = 1; j < Col; j++)
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
		for (int k = 0; k < Row; k++)
			if (array[k][row_min_j] > col_max)
			{
				col_max = array[k][row_min_j];
				col_max_i = k;
			}

		if (row_min_i == col_max_i)
			cout << "Saddle point: " << col_max
			<< "[" << row_min_i << "]"
			<< "[" << row_min_j << "]" << endl;

		for (int j = row_min_j + 1; j < Col; j++)
		{
			if (array[row_min_i][j] == row_min)
			{
				col_max_i = row_min_i;
				row_min_j = j;

				goto check;
			}
		}
	}
	
}

template <class TypeAr>
void start(string name) 
{
	TypeAr array[Row][Col];

	//reading and print array
	readArr(array, name);
	printArr(array);

	//find sum array
	findSum(array);

	//find Saddle Point
	FaindSaddlePoint(array);
}

int main() 
{
error:
	cout << "Select the data type (0-integer, 1-double, 2-float): ";
	string select;
	cin >> select;
	if (select == "0") 
	{
		start<int>("int");
	}
	else if (select == "1") 
	{
		start<double>("double");
	}
	else if (select == "2") 
	{
		start<float>("float");
	}
	else 
	{
		cout << "Error input! (Only 0/1/2)" << endl;
		goto error;
	}
	return 0;
}
