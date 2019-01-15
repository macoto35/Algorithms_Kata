#include <iostream>

using namespace std;

class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
		int operator ++();
		int operator --();
};

Number::Number(int number)
{
	this->num = number;
}

void Number::print()
{
	cout << this->num << endl;
}

int Number::operator ++()
{
	this->num += 1;
	return this->num;
}

int Number::operator --()
{
	this->num -= 1;
	return this->num;
}

void main()
{
	Number a(1);
	a.print();

	++a; // a.operator++();
	a.print();

	--a; // a.operator--();
	a.print();

	int b = 0;
	b = ++a;
	a.print();
	cout << b << endl;
}
