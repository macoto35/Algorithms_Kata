#include <iostream>

using namespace std;

/*
C++ supports default parameter values for function
*/
void print(int a = 0, int b = 0);

int main(void)
{
	print(12, 35);
	print(12);
	print();
}

void print(int a, int b)
{
	cout << a << " / " << b << endl;
}
