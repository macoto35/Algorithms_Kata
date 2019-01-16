#include <iostream>

using namespace std;

class father {
	protected:
		int num;
	public:
		father(int number = 0);
		void print();
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
		void print();
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
