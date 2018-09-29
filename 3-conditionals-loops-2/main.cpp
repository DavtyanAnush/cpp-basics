#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	double x, x1, x2, dx, y,p, eps;
	int n;
	const double EPS = DBL_EPSILON;
	const int n=100;
	check:
	cout << "In ln(1-x), -1 <= x < 1"<<endl<< "Enter x1, x2, dx, eps" << endl;
	cin >> x1 >> x2 >> dx >> eps;
	if (((abs(dx) < EPS)||((x1 >= 1)||(x1 < -1))||((x2 >= 1)||(x2 < -1))))
	{
		cout << "Input error" << endl;
		goto check;
	}
	cout << string(41, '-') << endl; 
	cout << "|"; 
	cout.width(5); 
	cout << "n"; 
	cout.width(5); 
	cout << "|";
	cout.width(5); 
	cout << "x";
	cout.width(5);
	cout << "|"; 
	cout.width(5);
	cout << "ln(1-x)";
	cout.width(5);
	cout << "|";
	cout.width(5);
	cout << "y";
	cout.width(5);
	cout << "|"<<endl;
	cout << string(41, '-') << endl;
	x = x1;
	while (x<x2)
	{
	  int i = 1;
      while (i<n)
	  {
		y +=(pow(x, i) / i);
		i++; 
	  }
	           p = log(1 - x);
	y = -1*y;
	cout << "|";
	cout.width(5);
	cout << showpos<< i;
	cout.width(5);
	cout << "|";
	cout.width(5);
	cout << fixed;
	cout.precision(eps);
	cout << showpos << x;
	cout.width(5);
	cout << "|"; 
	cout.width(5);
	cout << showpos << p;
	cout.width(5);
	cout << "|";
	cout.width(5);
	cout << showpos << y;
	cout.width(5);
	cout << "|"<<endl;
	x = x + dx;
	}	
	return 0;
}