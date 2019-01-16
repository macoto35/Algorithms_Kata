#include <iostream>

using namespace std;

class father {
	protected:
		int num;
	public:
		void print();
		void print(int n);
};

void father::print()
{
	cout << "father - print()" << endl;
	cout << this->num << endl;
}

void father::print(int n)
{
	cout << "father - print(int n)" << endl;
	for (int i = 0; i < 5; i++)
		cout << this->num << endl;
}

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
	cout << "son - print()" << endl;
	cout << this->num << endl;
}

void main()
{
	son s(5);
	s.print();
	
	//s.print(2); // this function also overrided by son so cannot execute but we can do like below
	s.father::print();
	s.father::print(2);

}
