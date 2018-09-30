#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double x, x1, x2, dx, y=0,p, eps;
	const double EPS = 1e-15;
	const int n=100;

	check:
	cout << "In ln(1-x), -1 <= x < 1"<<endl<< "Enter x1, x2, dx, eps" << endl;
	cin >> x1 >> x2 >> dx >> eps;
	if (((abs(dx) < EPS)||((x1 >= 1)||(x1 < -1))||((x2 >= 1)||(x2 < -1))))
	{
		cout << "Input error" << endl;
		goto check;
	}
	cout << string(73, '-') << endl; 
	cout << "|" << setw(9) << "n" << setw(9);
	cout << "|" << setw(9) << "x" << setw(9);
	cout << "|" << setw(9) << "ln(1-x)" << setw(9);
	cout << "|" << setw(9) << "y" << setw(9)<< "|" << endl;
	cout << string(73, '-') << endl;
	x = x1;
	while (x<=x2)
	{
	  int i = 1;
      while (i<n)
	  {
		y +=(pow(x, i) / i);
		if (abs(y) < eps)
			break;
		i++; 
	  }
	  y = -1*y;
	  p = log(1 - x);
	  cout << "|" << setw(11) << i << setw(7) << "|";
	  cout << setw(11) << x << setw(7) << "|";
	  cout << setw(11) << p << setw(7) << "|";
	  cout << setw(11) << y << setw(7) << "|"<< endl;
	  x += dx;
	}
	cout << string(73, '-') << endl;
	return 0;
}