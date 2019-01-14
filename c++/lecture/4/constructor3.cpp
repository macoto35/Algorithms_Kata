#include <iostream>

using namespace std;

class Number {
		int num;
	public:
		Number();
		Number(int number);
		void print();
};

Number::Number()
{
	num  = 0;
}

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
	Number b(2);

	a.print();
	b.print();
}
