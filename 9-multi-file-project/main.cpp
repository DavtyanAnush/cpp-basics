#include "func.h"

int main()
{
	int n = CreateArray();

	float *array = new float[n];

	EnterEelements(array, n);
	
	cout << "Min=" << FindMinimum(array, n) << endl;
	
	if (SumElements(array, n)!=0)
	cout << "Sum=" << SumElements(array, n) << endl;
	else cout << "No two positive elements were found" << endl;

	SortArray(array, n);

	cout << "New array: ";
	PrintArray(array, n);

	delete[] array;
	return 0;
}