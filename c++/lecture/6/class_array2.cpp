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
	Number a[5] = {
		Number(10),
		Number(20),
		Number(),
		Number(30),
		Number(40)
	};

	for (int i = 0; i < 5; i++)
		a[i].print();
}
