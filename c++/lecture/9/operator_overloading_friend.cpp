#include <iostream>

using namespace std;

class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
		friend Number operator -(Number a, Number b);
};

Number::Number(int number)
{
	this->num = number;
}

void Number::print()
{
	cout << this->num << endl;
}

Number operator -(Number a, Number b)
{
	Number result;

	result.num = a.num - b.num;

	return result;
}

void main()
{
	Number a(10), b(7), result;

	result = a - b; // Or operator -(a, b);

	result.print();
}
