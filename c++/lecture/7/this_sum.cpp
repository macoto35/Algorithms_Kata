#include <iostream>

using namespace std;

class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
		Number add(Number add_num);
};

Number::Number(int number)
{
	this->num = number;
}

void Number::print()
{
	cout << this->num << endl;
}

Number Number::add(Number add_num)
{
	Number result;
	result.num = this->num + add_num.num;

	return result;
}

void main()
{
	Number a(5), b(10), result;

	result = a.add(b);
	result.print();
}
