#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double x, x1, x2, dx, y, eps;
	const double kEPS = 1e-15;
	const int i_max=100;

	check:
	cout << "ln(1-x), -1 <= x < 1"<<endl<< "Enter x1, x2, dx, eps" << endl;
	cin >> x1 >> x2 >> dx >> eps;
	if (((abs(dx) < kEPS)||((x1 >= 1)||(x1 < -1))||((x2 >= 1)||(x2 < -1))))
	{
		cout << "Input error" << endl;
		goto check;
	}
	cout << string(73, '-') << endl; 
	cout << "|" << setw(9) << "x" << setw(9);
	cout << "|" << setw(9) << "ln(1-x)" << setw(9); 
	cout << "|" << setw(9) << "y" << setw(9);
	cout << "|" << setw(9) << "n" << setw(9)<< "|" << endl;
	cout << string(73, '-') << endl;

	cout << fixed;
	cout.precision(6);

	x = x1;
	
	while (x<=x2)
	{
		cout << "|" << setw(11) << x << setw(7) << "|";
		cout << setw(11) << log(1 - x) << setw(7) << "|";
		
		int i = 0;
		y = 0;

      while (abs(y) <= eps)
	  {
		i++;
		y +=(pow(x, i) / i);
		
		if (i > i_max) 
		break;
		
	  }
	   if (i > i_max)
		  cout << setw(11) << "Excess limit" << setw(6) << "|";
	   else 
		  cout << setw(11) << -1 * y << setw(7) << "|";
	   cout << setw(11) << i << setw(7) << "|" << endl;
	   x += dx;
	}
	cout << string(73, '-') << endl;
	return 0;
}