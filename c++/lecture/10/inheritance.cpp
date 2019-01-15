/*
- parent: base class / child: derived class

- Access Specifier
specifier | same class | derived(child) class | outside the class |
-------------------------------------------------------------------
private   | Y          | N                    | N                 |
protected | Y          | Y                    | N                 |
public    | Y          | Y                    | Y                 |

- example (father: base class, son: derived class)
class father {};
class son : public father {};

- access specifier in front of base class
* accessibility in public inheritance
accessibility     | private | protected | public
-------------------------------------------------
own class         |    Y    |     Y     |   Y
derived class     |    N    |     Y     |   Y
2nd derived class |    N    |     Y     |   Y

* accessibility in protected inheritance
accessibility     | private | protected | public
----------------------------------------------------------------------
own class         |    Y    |     Y     |   Y
derived class     |    N    |     Y     |   Y (inherited as protected)
2nd derived class |    N    |     Y     |   Y

* accessibility in private inheritance
accessibility     | private | protected                | public
---------------------------------------------------------------------------------
own class         |    Y    | Y                        | Y
derived class     |    N    | Y (inherited as private) | Y (inherited as private)
2nd derived class |    N    | N                        | N
*/
#include <iostream>

using namespace std;

class father {
	private:
		int a;
	protected:
		int b;
	public:
		void init();
		void print();
};

void father::init()
{
	this->a = this-> b = 0;
}

void father::print()
{
	cout << this->a << "/" << this->b << endl;
}

class son : public father {
	public:
		void input(int data);
		void print();
};

void son::input(int data)
{
	// this->a = data; -- cannot access a: private
	this->b = data;
}

void son::print()
{
	// cout << this->a << endl; -- cannot access a: private
	cout << this->b << endl; 
}

void main()
{
	father a;
	a.init();
	a.print();

	son b;
	b.init();
	b.print();

	b.input(2);
	b.print();
}
