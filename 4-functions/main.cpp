#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void printTableHead() 
{
	cout << string(73, '-') << endl;
	cout << "|" << setw(9) << "x" << setw(9);
	cout << "|" << setw(9) << "ln(1-x) built-in" << setw(2);
	cout << "|" << setw(9) << "  ln(1-x) series ";
	cout << "|" << setw(9) << "n" << setw(9) << "|" << endl;
	cout << string(73, '-') << endl;
}

double computeLnSeries(double eps, int &n, double x,  const int kMaxIter) 
{
	double nth_term;
	double ln = 0;
	for (n = 1; n < kMaxIter; n++)
	{
		nth_term = -pow(x, n) / n;
		ln += nth_term;

		if (abs(nth_term) < eps)
			break;
	}
	return ln;
}


void printResult(int n, const int kMaxIter, double ln, double x) 
{
	cout << "|" << setw(11) << x << setw(7) << "|";
	cout << setw(11) << log(1 - x) << setw(7) << "|";
	if (n == kMaxIter) {
		cout << setw(11) << "Excess limit" << setw(6) << "|";
		cout << setw(11) << " " << setw(7) << "|" << endl;
	}
	else
	{
		cout << setw(11) << ln << setw(7) << "|";
		cout << setw(11) << n << setw(7) << "|" << endl;
	}
}

int main()
{
	double x, x1, x2, dx, ln, eps;
	const double kEps = 1e-15;
	int n;
	const int kMaxIter = 1000000;

check:
	cout << "ln(1-x), -1 <= x < 1" << endl << "Enter x1, x2, dx, eps" << endl;
	cin >> x1 >> x2 >> dx >> eps;
	if ((dx < kEps) || (eps < kEps) || (x1 < -1) || (x1 >= x2) || (x2 >= 1))
	{
		cout << "Input error" << endl;
		goto check;
	}

	printTableHead();

	cout << fixed;
	cout.precision(6);

	x = x1;
	while (x <= x2)
	{
		ln = computeLnSeries(eps, n, x, kMaxIter);
		printResult(n, kMaxIter, ln, x);
		x += dx;
	}
	cout << string(73, '-') << endl;

	return 0;
}