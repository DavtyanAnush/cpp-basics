#include "func.h"

int CreateArray()
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

float FindMinimum(float array[], int n)
{
	float min = array[0];
	for (int i = 1; i < n; i++)
		if (min > array[i])
			min = array[i];
	return min;
}

float SumElements(float array[], int n)
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
	}
	
	return s;
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

void PrintArray(float array[], int n)
{
	
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}