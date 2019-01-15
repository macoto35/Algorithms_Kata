#include <iostream>

using namespace std;

class Number {
	protected:
		int a;
		int b;
	public:
		void init(int a, int b);
};

void Number::init(int a, int b)
{
	this->a = a;
	this->b = b;
}

class Plus : public Number {
	private:
		int result;
	public:
		void add();
		void print();
};

void Plus::add()
{
	result = this->a + this->b;
}

void Plus::print()
{
	cout << "a + b result: " << this->result << endl;
}

void main()
{
	Plus a;

	a.init(2, 3);
	a.add();
	a.print();
}
