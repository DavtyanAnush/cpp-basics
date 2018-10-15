#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	
	string text, p;
	ifstream fin("text.txt");

	if (!fin.is_open()) {
		cout << "Can't open file!\n";
		return 1;
	}

  stop:
	while (getline(fin, text, '.')||getline(fin, text, '!')||getline(fin, text, '?')) {
		for (int i = 1; i < text.length(); i++) {
			if (text[i] == ',') {
				goto stop;
			}
		}
		cout << text << ".";
	}

	return 0;
}