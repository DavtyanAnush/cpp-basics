#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x, x1, x2, dx, y;
	int n,eps;
	cout << "Enter x1, x2, x3, eps" << endl;
	cin >> x1>>x2>>dx>>eps;
	cout << "Enter n" << endl;
	cin >> n;
	cout << "n |";
	cout.width(eps+4);
	cout.fill(' '); 
	cout << "x|";
	cout.width(eps + 4);
	cout.fill(' ');
	cout << "y|" << endl;
	x = x1;
	while (x<x2)
	{
	  int i = 1;
      while (i<n)
	  {
		y = 0;
		if((x<1)&(x>=-1))
			y +=(pow(x, i) / i);
		i++; 
	  }
	y = -1*y;
	cout << showpos<< i << '|';
	cout << fixed;
	cout.precision(eps);
	cout << showpos << x << '|';
	cout << fixed;
	cout.precision(eps);
	cout << showpos << y << '|'<<endl;
	x = x + dx;
	}	
	return 0;
}