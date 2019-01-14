#include <iostream>

using namespace std;

class Number {
		int num;
	public:
		Number(int number);
		void print();
};

Number::Number(int number)
{
	num = number;
}

void Number::print()
{
	cout << "num: " << num << endl;
}

void main()
{
	Number a(1);
	Number b = 2;

	a.print();
	b.print();
}
