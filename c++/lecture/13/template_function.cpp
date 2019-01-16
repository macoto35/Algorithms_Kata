#include <iostream>

using namespace std;

/*
templete: This allows us to create a function template whose functionality can be adapted to more than one type or class without repeating the entire code for each type.
*/
template <class Type>
void print(Type num);

void main()
{
	int i = 5;
	float f = -12.45;

	print(i);
	print(f);
}

template <class Type>
void print(Type num)
{
	cout << num << endl;
}
