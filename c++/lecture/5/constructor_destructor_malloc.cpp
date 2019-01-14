#include <iostream>

using namespace std;

class Number {
	private:
		int* arr;
		int size;
	public:
		Number(int num);
		~Number();
		void input(int num);
		void print();
};

Number::Number(int num)
{
	size = num;
	arr = new int[size];
}

Number::~Number()
{
	delete[] arr;
}

void Number::input(int num)
{
	for(int i = 0; i < size; i++)
		arr[i] = num;
}

void Number::print()
{
	for(int i = 0 ; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void main()
{
	Number a(5);

	a.input(7);
	a.print();
}
