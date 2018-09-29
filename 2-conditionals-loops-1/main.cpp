#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	double x1, x2, dx, a, b, c, F, x;
	const double EPS = DBL_EPSILON;
	cout << "Enter a, b, c." << endl;
	cin >> a >> b >> c;
	cout << "Enter x1" << endl;
	cin >> x1;
	cout << "Enter x2" << endl;
	cin >> x2;
	cout << "Enter dx" << endl;
	cin >> dx;
	if ((abs(dx) >EPS)&(abs(c) > EPS))
	{
		cout << string(41, '-') << endl;
		cout << "|";
		cout.width(10);
		cout << "x";
		cout.width(10);
		cout << "|";
		cout.width(10);
		cout << "F";
		cout.width(10);
		cout << "|" << endl;
		cout << string(41, '-') << endl;
		cout << fixed;
		cout.precision(3);
		x = x1;
		while (x <= x2)
		{
			if ((c < 0)&(abs(b) > EPS)) {
				F = a * pow(x, 2) + pow(b, 2)*x;
			}
			else
			{
				if ((c > 0)&(abs(b) < EPS))
				{
					if (abs(x + c) >EPS)
						F = (x + a) / (x + c);
					else
						cout << "Oshibka deleniya na '0'!";
				}
				else
						F = x / c;
			} 
			cout << "|";
			cout.width(10);
			cout << x;
			cout.width(10);
			cout << "|";
			cout.width(10);
			if (((int(a)&int(b)) | (int(a)&int(c))) != 0)
				cout << F;
			else
				cout << int(F);
			cout.width(10);
			cout << "|" << endl;
			x += dx;
		}
		cout << string(41, '-') << endl;
	}
	else
		cout << "Oshibka!";
	return 0;
}