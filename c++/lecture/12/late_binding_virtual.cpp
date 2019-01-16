#include <iostream>

using namespace std;

/*
<< early / static binding>>
- depends on pointer variable type. (e.g. father*)

<< late / dynamic binding >>
- call a method where pointer actually indicates
- use 'virtual' keyword (for method only, not function)
- derived class's method become a virtual function if base class 
- less efficient than early binding: runtime biding
- In java all methods are virtual except static, final, private (because those 3 methods cannot be override, static can override but it belongs to class not object)
*/
class father {
	protected:
		int num;
	public:
		father(int number = 0);
		virtual void print();
};

father::father(int number)
{
	this->num = number;
}

void father::print()
{
	cout << "print in father: ";
	cout << this->num << endl;
}

class son : public father {
	public:
		son(int number = 0);
		void print(); // base class's method is virtual therefore this function is virtual too
};

son::son(int number) : father(number)
{
	this->num = number;
}

void son::print()
{
	cout << "print in son: ";
	cout << this->num << endl;
}

void main()
{
	father* fpt;
	son s(20);

	fpt = &s;

	fpt->print();
}
