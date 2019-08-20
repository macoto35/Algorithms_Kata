#include <iostream>
#include <string>

using namespace std;

void recPermute(string sofar, string rest)
{
	if (rest == "") {
		cout << "result: " << sofar << endl;
	} else {
		for (int i = 0; i < rest.length(); i++) {
			string next = sofar + rest[i];
			string remaining = rest.substr(0, i) + rest.substr(i+1);
			recPermute(next, remaining);
		}
	}
}

void main()
{
	string s;
	getline(cin, s);

	recPermute("", s);
}
