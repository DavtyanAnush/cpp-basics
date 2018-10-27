#include <iostream>

using namespace std;

int main()
{
	const int n = 8;
	float array[n] = { 0.21 ,-1.65 ,54.2, 26.0, 10.6, -3.2, 0.0, -4.2 };

	for (int i = 0; i < n; i++)
		cout << array[i] << " ";

	float min = array[0];
	for (int i = 1; i < n; i++)
		if (min > array[i])
			min = array[i];
	cout << "\nMin=" << min << endl;

	int k1 = -1, k2 = -1;
	for (int i = 0;i<=n; i++)
		if (array[i] > 0)
		{
			k1 = i;
			break;
		}
	for (int i = n-1;i>=0; i--)
		if (array[i] > 0)
		{
			k2 = i;
			break;
		}

	float s = 0;
	if ((k1 > -1)&&(k1 < k2)) 
	{
		for (int i = k1 + 1; i < k2; i++) {
			s += array[i];
		}
		cout << "Sum=" << s << endl;
	}
	else cout << "No two positive elements were found"<<endl;

	for (int i = n - 1; i >= 0; i--)
		if (array[i] == 0)
		{
			for (int j = i; j >= 0; j--)
				array[j] = array[j - 1];
			array[0] = 0;
		}

	cout << "New array: ";
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";

  return 0;
}