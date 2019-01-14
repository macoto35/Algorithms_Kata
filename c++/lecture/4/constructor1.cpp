#include <iostream>

using namespace std;

class Number {
		int num;
	public:
		Number();
		void print();
};

Number::Number()
{
	num = 0;
}

void Number::print()
{
	cout << "num: " << num << endl;
}

void main()
{
	Number a;
	a.print();
}
