#include <iostream>

using namespace std;

class Number {
		int num;
	public:
		Number(int number = 0);
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
	Number a;
	Number b = 5;

	a.print();
	b.print();
}
