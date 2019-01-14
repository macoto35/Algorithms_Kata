#include <iostream>

using namespace std;

class Number {
		int num;
	public:
		Number(int number = 0);
		~Number();
		void print();
};

Number::Number(int number)
{
	num = number;
}

Number::~Number()
{
	cout << "class destructed" << endl; 
}

void Number::print()
{
	cout << "num : " << num << endl;
}

void main()
{
	Number a;
	Number b = 5;

	a.print();
	b.print();
}
