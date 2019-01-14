#include <iostream>

using namespace std;

class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
		friend Number add(Number a, Number b);
};

Number::Number(int number)
{
	this->num = number;
}

void Number::print()
{
	cout << this->num << endl;
}

Number add(Number a, Number b)
{
	Number result;
	/* 
	 without friend - cannot access result.num, a.num and b.num: private access only can access inside of class
	 with friend - general function can access class member variable but breach one of the OOP rule: data abstraction.
	*/
	result.num = a.num + b.num;

	return result;
}

void main()
{
	Number a(5), b(10), result;

	result = add(a, b);

	result.print();
}
