#include <iostream>

using namespace std;

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

/*
can't inherit father(int data) constructor from father class.
but inherit father() constructor from father class - derive class required base class constructor to inherit variables and functions from the parent.
*/
class son : public father {
};

void main()
{
	son a(100);
	a.print();
}
