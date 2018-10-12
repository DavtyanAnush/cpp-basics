#include "func.h"
#include <iostream>

using namespace std;

int CreationArray()
{
	int n;
check:
	cout << "Write the number of array elements (n>0), n=";
	cin >> n;
	if (n <= 0) {
		cout << "Input error" << endl;
		goto check;
	}
	return n;
}

void EnterEelements(float array[], int n)
{
	cout << "Enter elements: ";
	for (int i = 0; i < n; i++)
		cin >> array[i];
}
void FaindMinimum(float array[], int n)
{
	int min = array[0];
	for (int i = 1; i < n; i++)
		if (min > array[i])
			min = array[i];
	cout << "Min=" << min << endl;
}
void SumElements(float array[], int n)
{
	int k1 = -1,
		k2 = -1;
	for (int i = 0; i <= n; i++)
		if (array[i] > 0)
		{
			k1 = i;
			break;
		}
	for (int i = n - 1; i >= 0; i--)
		if (array[i] > 0)
		{
			k2 = i;
			break;
		}

	float s = 0;
	if ((k1 > -1) && (k1 < k2))
	{
		for (int i = k1 + 1; i < k2; i++) {
			s += array[i];
		}
		cout << "Sum=" << s << endl;
	}
	else cout << "No two positive elements were found" << endl;
}

void SortArray(float array[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		if (array[i] == 0)
		{
			for (int j = i; j >= 0; j--)
				array[j] = array[j - 1];
			array[0] = 0;
		}
}
void PrintNewArray(float array[], int n)
{
	cout << "New array: ";
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}