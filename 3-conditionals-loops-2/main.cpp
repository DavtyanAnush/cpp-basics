#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double x, x1, x2, dx, y, sum, eps;
	const double kEPS = 1e-15;
	const int i_max=100;

	check:
	cout << "ln(1-x), -1 <= x < 1"<<endl<< "Enter x1, x2, dx, eps" << endl;
	cin >> x1 >> x2 >> dx >> eps;
	if (((fabs(dx) < kEPS)||((x1 >= 1)||(x1 < -1))||((x2 >= 1)||(x2 < -1))))
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
	int n = 1;
	while (x<=x2)
	{
		cout << "|" << setw(11) << x << setw(7) << "|";
		cout << setw(11) << log(1 - x) << setw(7) << "|";
		
		int i = 1;
		sum = -1*x;

      while (fabs(sum)>= eps)
	  {
		i++;
		if (i % 2 == 0) 
		{
			y =-1*(pow(x, i) / i);
			sum = sum + y;
			n++;
		}
		if (n > i_max) 
		 break;
	  }
	   if (n > i_max) 
	   {
		  cout << setw(11) << "Excess limit" << setw(6) << "|";
		  cout << setw(11) << " " << setw(7) << "|" << endl;
	   }
	   else 
	   {
		   cout << setw(11) << sum << setw(7) << "|";
		   cout << setw(11) << n << setw(7) << "|" << endl;
	   }
	   x += dx;
	}
	cout << string(73, '-') << endl;
	return 0;
}