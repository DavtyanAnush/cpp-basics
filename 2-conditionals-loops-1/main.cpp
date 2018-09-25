#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x1, x2, dx, a, b, c,i, F=0,x;
	cout << "Enter a, b, c." << endl;
	cin >> a >> b >> c;
	cout << "Enter x1" << endl;	
	cin >> x1;
	cout << "Enter x2" << endl;
	cin >> x2;
	cout << "Enter dx" << endl;
	cin >> dx;
	x = x1;
	while (x < x2)
	{
		if ((c < 0)&(b != 0)) {
			F = a * pow(x, 2) + pow(b, 2)*x;
		}
		else
		{
			if ((c > 0)&(b == 0))
		    {
			F = (x + a) / (x + c);
		    }
			else
			F=x/c;
		}
		
		cout << F << '|';
		x = x + dx;
	}
	return 0;
}