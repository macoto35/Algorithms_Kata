#include <iostream>

using namespace std;

/*
- A class becomes abstract class if there is one pure virtual fuction
- Abstract class cannot be instantiated - for base class only (e.g. Animal class for Dog, Cat and Cow)
- Does not need implementation of method so it has to be implemented on a derived class
*/
class father {
	protected:
		int num;
	public:
		virtual void print() = 0; // pure virtual function
};

class son : public father {
	public:
		son(int number = 0);
		void print();
};

son::son(int number)
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
	son s(20);
	s.print();
}
