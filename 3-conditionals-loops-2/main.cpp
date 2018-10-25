#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	double x, x1, x2, dx, nth_term, ln, eps;
	const double kEPS = 1e-15;
	int n, max_iter = 1000000;

	check:
	cout << "ln(1-x), -1 <= x < 1"<<endl<< "Enter x1, x2, dx, eps" << endl;
	cin >> x1 >> x2 >> dx >> eps;
	if ((dx < kEPS)||(eps < kEPS)||(x1 < -1)||(x1>=x2)||(x2 >= 1))
	{
		cout << "Input error" << endl;
		goto check;
	}
	cout << string(73, '-') << endl; 
	cout << "|" << setw(9) << "x" << setw(9);
	cout << "|" << setw(9) << "ln(1-x) built-in" << setw(2);
	cout << "|" << setw(9) << "  ln(1-x) series ";
	cout << "|" << setw(9) << "n" << setw(9)<< "|" << endl;
	cout << string(73, '-') << endl;

	cout << fixed;
	cout.precision(6);

	x = x1;
	
	while (x<=x2)
	{
		cout << "|" << setw(11) << x << setw(7) << "|";
		cout << setw(11) << log(1 - x) << setw(7) << "|";
		ln = 0;
		for (n = 1; n < max_iter; n++)
		{
			nth_term = -pow(x, n) / n;
			ln += nth_term;

			if (abs(nth_term) < eps)
				break;
		}
		if (n == max_iter) {
			cout << setw(11) << "Excess limit" << setw(6) << "|";
			cout << setw(11) << " " << setw(7) << "|" << endl;
		}
		else 
		{
			cout << setw(11) << ln << setw(7) << "|";
			cout << setw(11) << n << setw(7) << "|" << endl;
		}
	   x += dx;
	}
	cout << string(73, '-') << endl;
	return 0;
}