#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct workers
{
	string name, status;
	int year;
};

int main()
{
	const int kWorkers = 10;
	workers workers[kWorkers];

	for (int i=0; i < kWorkers; i++)
	{
		cout << "Enter the name of the employee (e.g., Ivanov I.I.) " << i + 1 << ": ";
		getline(cin, workers[i].name);
		cout << "Enter the job title of the employee (e.g., software developer) " << workers[i].name << ": ";
		getline(cin, workers[i].status);
		cout << "Enter the year of employment (e.g.,2015): ";
		cin >> workers[i].year;
		cout << endl;
		cin.get();
	}

	for (int i = 0; i < kWorkers; i++)
	{
		for (int j = 0; j < kWorkers - i - 1; j++)
		{
			if (workers[j].name.compare(workers[j + 1].name) > 0)
			{
				swap(workers[j], workers[j + 1]);
			}
		}
	}

	cout << "Name-Status-Year" << endl;
	for (int i = 0; i < kWorkers; i++)
	{
		cout << workers[i].name<< " - " <<  workers[i].status << " - " << workers[i].year << "\n";
	}

	int stazh;
	cout << "Enter the work experience (e.g., 5): ";
	cin >> stazh;
	cout << "Works more than " << stazh << " years: " << endl;
	int r = 0;
	for (int i = 0; i < kWorkers; i++)
	{
		if ((2018 - workers[i].year) > stazh) 
		{
		cout << workers[i].name << endl;
		r += 1;
	    }
	}
		if (r==0)
		 cout << "No employees working for " << stazh << " years.";
	
	return 0;
}