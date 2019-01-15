#include <iostream>

using namespace std;

/*
1. child class requires default constructor of parent class (e.g. father(); )
   : parent class should be created before child class in order to use parent class' variables and methods
 
2. If you define a class without any constructor, the compiler will synthesize a default constructor for you.
   If,  however, you do define a constructor, the compiler will not synthesize a default constructor for you so always define default constructor for this case.

3. derived class can choose one of base class' constructor.

e.g. son::son(int data) === son::son(int data) : father()
e.g. son::son(int data) : father(data)

*/

/*
-- error case: default constructor is not exist in the parent class
class father {
	protected:
		int num;
	public:
		father(int data);
		void print();

};

father::father(int data)
{
	this->num = data;
}

void father::print()
{
	cout << this->num << endl;
}

class son : public father {
	public:
		son(int data);
};

son::son(int data)
{
	this->num = data;
}

void main()
{
	son a(10);
	a.print();
}
*/

/* -- add default constructor in the parent class
class father {
	protected:
		int num;
	public:
		father();
		father(int data);
		void print();

};

father::father() {}

father::father(int data)
{
	this->num = data;
}

void father::print()
{
	cout << this->num << endl;
}

class son : public father {
	public:
		son(int data);
};

son::son(int data) : father()
{
	this->num = data;
}

void main()
{
	son a(10);
	a.print();
}
*/

/* let derive class know that which constructor to use */
class father {
	protected:
		int num;
	public:
		father(int data);
		void print();

};

father::father(int data)
{
	this->num = data;
}

void father::print()
{
	cout << this->num << endl;
}

class son : public father {
	public:
		son(int data);
};

son::son(int data) : father(data)
{
	this->num = data;
}

void main()
{
	son a(10);
	a.print();
}
