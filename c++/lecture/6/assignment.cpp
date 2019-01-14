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

void print(Number* ptr);

void main()
{
	Number a[5] = {
		Number(10),
		Number(11),
		Number(),
		Number(12),
		Number(13)
	};

	print(a);
}

void print(Number* ptr)
{
	for (int i = 0; i < 5; i++)
		ptr++->print();
}
