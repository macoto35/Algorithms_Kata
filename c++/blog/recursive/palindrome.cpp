#include <iostream>
#include <string>

using namespace std;

bool palindrome(string str)
{
	cout << "enter: " << str << endl;
	if (str.empty())
		return true;
	return str[0] == str[str.length() - 1] && palindrome(str.substr(1, str.length() - 2));
}

int main()
{
	string str;
	getline(cin, str);

	cout << str <<  (palindrome(str) ? " is " : " is not ") << "a palindrome! " << endl;
}
