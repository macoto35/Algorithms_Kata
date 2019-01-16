#include <iostream>

using namespace std;

template <class N>
class Number {
	protected:
		N num;
	public:
		Number(N number = 0);
		void print();
};

/*
Each method defines 'template <class (name)>' & 'Number<(name)>' part
*/
template <class N>
Number<N>::Number(N number)
{
	this->num = number;
}

template <class N>
void Number<N>::print()
{
	cout << this->num << endl;
}

void main()
{
	/*
	like java generic, specified the type
	*/
	Number<int> in(5);
	Number<float> fn(-12.5);

	in.print();
	fn.print();
}
