#include <iostream>

using namespace std;

/*
cl /EHsc a.cpp

/EHsc: enable c++ exception handling
*/
int main(void)
{
	int a, b;

	cout << "enter a first interger!";
	cin >> a;

	cout << "enter a second interger!";
	cin >> b;

	cout << a << " + " << b << " = " << a+b << endl;

	return 0;
}
