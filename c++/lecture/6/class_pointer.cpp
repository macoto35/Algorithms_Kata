#include <iostream>

using namespace std;

class Number {
	private:
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
	cout << num << endl;
}

void main()
{
	Number a(12);
	Number* p;

	p = &a;

	a.print();
	p->print();
}
