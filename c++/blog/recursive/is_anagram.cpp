#include <iostream>
#include <string>

using namespace std;


bool is_contain(string s)
{
	string strs[] = {"abc", "query", "exit"};
	int size = sizeof(strs) / sizeof(string);
	
	for (int i = 0; i < size; i++) {
		if (strs[i] == s)
			return true;
	}
	return false;
}

bool is_anagram(string sofar, string rest)
{
	if (rest == "") {
		bool result =is_contain(sofar);
		cout << sofar << "? " << result << endl;
		return result;
	} else {
		for (int i = 0; i < rest.length(); i++) {
			string next = sofar + rest[i];
			string remaining = rest.substr(0, i) + rest.substr(i+1);
			if (is_anagram(next, remaining))
				return true;
		}
	}
	return false;
}

void main()
{
	string s;
	getline(cin, s);

	cout << is_anagram("", s) << endl;
}
