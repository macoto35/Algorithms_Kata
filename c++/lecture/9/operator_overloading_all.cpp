#include <iostream>

using namespace std;

class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
		friend Number operator -(Number a, Number b);
		Number operator-();
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

Number Number::operator-()
{
	Number result;

	result = -this->num;

	return result;
}

void main()
{
	Number a(10), b(20), result;

	result = -a-b; // Or operator-(a.operator-(), b);
	result.print();

	result = -(a-b); // Or result = operator-(a, b); result.operator-();
	result.print();

	result = -result; // Or result.operator-()
	result.print();


	/*result = operator-(a.operator-(), b);
	result.print();

	result = operator-(a, b);
	result = result.operator-();
	result.print();

	result = result.operator-();
	result.print();*/
}
