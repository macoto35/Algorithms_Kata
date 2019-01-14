#include <iostream>

using namespace std;

class Number {
	private:
		int num;
	public:
		Number(int number = 0);
		void print();
		friend void increase(Number& a);
		friend void increase(Number* a);
};

Number::Number(int number)
{
	this->num = number;
}

void Number::print()
{
	cout << this->num << endl;
}

void increase(Number& a)
{
	a.num++;
}

void increase(Number* a)
{
	a->num++;
}

void main()
{
	Number a(2);
	a.print();

	// call by reference
	increase(&a);
	a.print();

	// call by address
	increase(&a);
	a.print();

	/*
	References don't have their own addresses. Although references may be implemented as pointers, there is no need or guarantee of this.
        Unlike a pointer, once a reference is bound to an object, it can not be "reseated" to another object.
	The reference itself isn't an object (it has no identity; taking the address of a reference gives you the address of the referent; remember: the reference is its referent)
	*/
	int i = 7;
	int* ip = &i;
	int& ir = i;
	cout << "[i] value: " << i << ", address: " << &i << endl;
	cout << "[ip] value: " << ip << ", address: " << &ip << ", ref value: " << *ip << endl;
	cout << "[ir] value: " << ir << ", address: " << &ir << endl;
}
