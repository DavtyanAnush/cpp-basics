#include "func.h"

int main()
{
	int n = CreationArray();

	float *array = new float[n];

	EnterEelements(array, n);

	FaindMinimum(array, n);

	SumElements(array, n);

	SortArray(array, n);

	PrintNewArray(array, n);

	delete[] array;
	return 0;
}