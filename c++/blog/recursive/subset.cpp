#include <iostream>
#include <string>

using namespace std;

void subset(string sofar, string rest)
{
	if (rest == "") {
		cout << "result: " << sofar << endl;
	} else {
		subset(sofar + rest[0], rest.substr(1));
		subset(sofar, rest.substr(1));
	}
}

void main()
{
	string s;
	getline(cin, s);

	subset("", s);
}
