#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x1, x2, dx, a, b, c, F,x;
<<<<<<< HEAD
	const long double EXP = 0.000000000001;
=======
>>>>>>> d192b99448a4cb50250bddaa67122bdb529fd82f
	cout << "Enter a, b, c." << endl;
	cin >> a >> b >> c;
	cout << "Enter x1" << endl;	
	cin >> x1;
	cout << "Enter x2" << endl;
	cin >> x2;
	cout << "Enter dx" << endl;
	cin >> dx;
	if (dx != 0) 
	{
<<<<<<< HEAD
	cout << "-----------------------------------------" << endl;
=======
	cout<<"-----------------------------------------"<<endl;
>>>>>>> d192b99448a4cb50250bddaa67122bdb529fd82f
	cout << "|";
	cout.width(10);
	cout <<"x";
	cout.width(10);
	cout << "|";
	cout.width(10);
	cout << "F";
	cout.width(10);
	cout << "|"<<endl;
	cout << "-----------------------------------------" << endl;
	x = x1;
<<<<<<< HEAD
		while (x <=x2)
		{
			if ((c < 0)&(abs(b)>EXP)){
				F = a * pow(x, 2) + pow(b, 2)*x;
			}
			else
			{
				if ((c > 0)&(abs(b)<EXP))
				{
					if (x + c != 0)
						F = (x + a) / (x + c);
					else
						cout << "Oshibka!";
				}
				else
					if (c != 0)
						F = x / c;
					else
						cout << "Oshibka!";
			}
			if (((int(a)&int(b)) | (int(a)&int(c))) != 0) 
			{
				cout << "|";
				cout.width(10);
				cout << fixed;
				cout.precision(3);
				cout << showpos << x;
				cout.width(10);
				cout << "|";
				cout.width(10);
				cout << F;
				cout.width(10);
				cout << "|" << endl;
			}
			else 
			{
				cout << "|";
				cout.width(10);
				cout << fixed;
				cout.precision(3);
				cout << showpos << x;
				cout.width(10);
				cout << "|";
				cout.width(10);
				cout << int(F);
				cout.width(10);
				cout << "|" << endl;
			}
			x += dx;
		}
		cout << "-----------------------------------------" << endl;
	}
=======
		while (x <x2)
		{
			if ((c < 0)&(b != 0)) {
				F = a * pow(x, 2) + pow(b, 2)*x;
			}
			else
			{
				if ((c > 0)&(b == 0))
				{
					if (x + c != 0)
						F = (x + a) / (x + c);
					else
						cout << "Oshibka!";
				}
				else
					if (c != 0)
						F = x / c;
					else
						cout << "Oshibka!";
			}
			if (((int(a)&int(b)) | (int(a)&int(c))) != 0) 
			{
				cout << "|";
				cout.width(10);
				cout << fixed;
				cout.precision(3);
				cout << showpos << x;
				cout.width(10);
				cout << "|";
				cout.width(10);
				cout << F;
				cout.width(10);
				cout << "|" << endl;
				x += dx;
			}
			else 
			{
				cout << "|";
				cout.width(10);
				cout << fixed;
				cout.precision(3);
				cout << showpos << x;
				cout.width(10);
				cout << "|";
				cout.width(10);
				cout << int(F);
				cout.width(10);
				cout << "|" << endl;
				x += dx;
			}
		}
		if ((c < 0)&(b != 0)) {
			F = a * pow(x2, 2) + pow(b, 2)*x2;
		}
		else
		{
			if ((c > 0)&(b == 0))
			{
				if (x2 + c != 0)
					F = (x2 + a) / (x2 + c);
				else
					cout << "Oshibka!";
			}
			else
				if (c != 0)
					F = x2 / c;
				else
					cout << "Oshibka!";
		}
		if (((int(a)&int(b)) | (int(a)&int(c)))!=0) 
		{
			cout << "|";
			cout.width(10);
			cout << fixed;
			cout.precision(3);
			cout << showpos << x2;
			cout.width(10);
			cout << "|";
			cout.width(10);
			cout << F;
			cout.width(10);
			cout << "|" << endl;
		}
		else
		{
			cout << "|";
			cout.width(10);
			cout << fixed;
			cout.precision(3);
			cout << showpos << x2;
			cout.width(10);
			cout << "|";
			cout.width(10);
			cout << int(F);
			cout.width(10);
			cout << "|" << endl;

		}
		cout << "-----------------------------------------" << endl;
	}
	
>>>>>>> d192b99448a4cb50250bddaa67122bdb529fd82f
	else
		cout << "Oshibka!";
	return 0;
}