#include <iostream>

using namespace std;

class father {
	protected:
		int num;
	public:
		void print();
};

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
