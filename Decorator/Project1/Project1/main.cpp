#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	cout << "Please choose the type(s) of notification." << endl;
	cout << "1. Facebook," << endl;
	cout << "2. SMS," << endl;
	cout << "3. Slack." << endl;
	cout << "Enter \"a b\" if you want to choose multiple types." << endl;
	string choice;
	cin >> choice;

	stringstream ss;
	ss << choice;

	int c1, c2, c3;
	ss >> c1 >> c2 >> c3;

	if (c1 == 1 && c2 == 0 && c3 == 0)
		cout << "Hello" << endl;

	return 0;
}