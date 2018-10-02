#include <iostream>

using namespace std;

int main()
{
	int i, n, k1, k2;
	float min, s = 0;
	cout << "Write the number of array elements, n=";
	cin >> n;
	float *array = new float[n];

	cout << "  Enter elements: ";
	for (i = 0; i < n; i++)
		cin >> array[i];

	min = array[0];
	for (i = 1; i < n; i++)
		if (min > array[i])
			min = array[i];

	for (i = 0;; i++)
		if (array[i] > 0)
		{
			k1 = i;
			break;
		}
	for (i = n;; i--)
		if (array[i] > 0)
		{
			k2 = i;
			break;
		}
	for (i = k1 + 1; i < k2; i++)
		s += array[i];

	cout << "\n  min=" << min;
	cout << "\n  Summa=" << s;

	cout << "\n  New array: ";
	for (i = 0; i < n; i++)
		if (array[i] == 0)
			cout << array[i] << " ";
	for (i = 0; i < n; i++)
		if (array[i])
			cout << array[i] << " ";

	delete[] array;
  return 0;
}