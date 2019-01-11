#include <iostream>

using namespace std;

void print(int num);
void print(float num);
void print(double num);

/*
C doesn't have overloading concept but c++ does:

void print(int num);
void print(float num);
void print(double num);

*/
int main(void)
{
	int i = 4;
	float f = -1.2;
	double d = 3.14;

	print(i);
	print(f);
	print(d);
}

void print(int num)
{
	cout << "[int] " << num << endl;
}

void print(float num)
{
	cout << "[float] " << num << endl;
}

void print(double num)
{
	cout << "[double] " << num << endl;
}
