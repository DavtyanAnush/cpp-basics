#include <iostream>

using namespace std;

int main()
{
	int i, n, j, k1=-1, k2=-1;
	float min, s = 0;
	check:
	cout << "Write the number of array elements (n>0), n=";
	cin >> n;
	if (n <= 0) {
		cout << "Input error" << endl;
		goto check;
	}

	float *array = new float[n];

	cout << "Enter elements: ";
	for (i = 0; i < n; i++)
		cin >> array[i];

	min = array[0];
	for (i = 1; i < n; i++)
		if (min > array[i])
			min = array[i];
	cout << "Min=" << min << endl;

	for (i = 0;i<=n; i++)
		if (array[i] > 0)
		{
			k1 = i;
			break;
		}
	for (i = n-1;i>=0; i--)
		if (array[i] > 0)
		{
			k2 = i;
			break;
		}

	if ((k1 > -1)&&(k1 < k2)) 
	{
		for (i = k1 + 1; i < k2; i++) {
			s += array[i];
		}
		cout << "Sum=" << s << endl;
	}
	else cout << "No two positive elements were found"<<endl;

	for (i = n - 1; i >= 0; i--)
		if (array[i] == 0)
		{
			for (j = i; j >= 0; j--)
				array[j] = array[j - 1];
			array[0] = 0;
		}

	cout << "New array: ";
	for (i = 0; i < n; i++)
		cout << array[i] << " ";

	delete[] array;
  return 0;
}