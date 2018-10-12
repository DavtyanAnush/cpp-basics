#include<iostream>
#include<string>
#include <iomanip>

using namespace std;

struct Worker
{
	string name,
		status;
	int year;
};

int main()
{
	const int kWorkers = 10;
	Worker worker[kWorkers];

	for (int i=0; i < kWorkers; i++)
	{
		cout << "Enter the name of the worker " << i + 1 << ": ";
		getline(cin, worker[i].name);
		cout << "Enter the status of the worker " << worker[i].name << ": ";
		getline(cin, worker[i].status);
		cout << "Enter the year of employment: ";
		cin >> worker[i].year;
		cin.get();
	}

	for (int i = 0; i < kWorkers; i++)
	{
		for (int j = 0; j < kWorkers - i - 1; j++)
		{
			if (worker[j].name.compare(worker[j + 1].name) > 0)
			{
				swap(worker[j], worker[j + 1]);
			}
		}
	}

	cout << string(55, '-') << endl;
	cout << "|" << setw(9) << "Name" << setw(9);
	cout << "|" << setw(9) << "Status" << setw(9);
	cout << "|" << setw(9) << "Year" << setw(9) << "|" << endl;
	cout << string(55, '-') << endl;
	for (int i = 0; i < kWorkers; i++)
	{
		cout << "|" << setw(12) << worker[i].name << setw(6);
		cout << "|" << setw(12) << worker[i].status << setw(6);
		cout << "|" << setw(9) << worker[i].year << setw(9) << "|" << "\n";
		cout << string(55, '-') << endl;
	}

	int stazh;
	cout << "Enter how many years work: ";
	cin >> stazh;
	cout << "Works more than " << stazh << " years: " << endl;
	for (int i = 0; i < kWorkers; i++)
	{
		if ((2018 - worker[i].year) > stazh)
		{
			cout << worker[i].name << endl;
		}
	}

	return 0;
}