#include <iostream>

using namespace std;

int main(void)
{
	char str[80];

	cout << "please enter any string!";
	// cin >> str; // cannot read blank
	cin.get(str, 20); // same as gets(str), read 19 characters + 1 null(\0) character string

	cout << str << endl;

	return 0;
}
