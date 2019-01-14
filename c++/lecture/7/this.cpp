#include <iostream>

using namespace std;

/*
member variable: have a separate memory location
method: share memory location

this: pointer. indicate current object
*/
class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
};

Number::Number(int number)
{
	this->num = number;
}

void Number::print()
{
	cout << this->num << endl;
}

void main()
{
	Number a(5);
	Number b(22);

	a.print();
	b.print();
}
