#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string text, p;
	ifstream fin("text.txt");

	if (!fin.is_open()) {
		cout << "Файл не может быть открыт!\n";
		return 1;
	}
  stop:
	while (getline(fin, text, '.')) {
		for (int i = 1; i < text.size(); i++) {
			if (text[i] == ',') {
				goto stop;
			}
		}
		cout << text << ".\n";
	}

	return 0;
}