#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float z1, z2, a;
	cout << "Enter a number" << endl;
	cin >> a;
	z1 = cos(a) + cos(2 * a) + cos(6 * a) + cos(7 * a);
	z2 = 4 * cos(a / 2)*cos(5 * a / 2)*cos(4 * a);
	cout << "z1=" << z1 << endl << "z2=" << z2 << endl;
	return 0;
}