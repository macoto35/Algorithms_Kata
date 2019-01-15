#include <iostream>

using namespace std;

class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
		Number operator +(Number new_num);
};

Number::Number(int number)
{
	this->num = number;
}

void Number::print()
{
	cout << this->num << endl;
}

Number Number::operator +(Number new_num)
{
	Number result;
	result.num = this->num + new_num.num;

	return result;
}

void main()
{
	Number a(10), b(20), result;

	result = a + b; // Or a.operator + (b)

	result.print();
}
