#include <iostream> 
#include <string>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

int main() {

	ifstream fin("text.txt");
	if (!fin.is_open()) 
	{
		cout << "Can't open file: text.txt!\n";
		return 1;
	}

	string text;
	char buf;
	while (!fin.eof()) 
	{
		fin.get(buf);
		text += buf;
		if ((buf == '?') || (buf == '.') || (buf == '!')) 
		{
			if (text.find(",") == -1)
				cout << text << endl;
			text = " ";
			buf = ' ';
		}
	}

	fin.close();
	return 0;
}