#include <iostream>

using namespace std;

class Lumpsum {
		int sum;
	public:
		Lumpsum();
		~Lumpsum();
		void add(int num);
};

Lumpsum::Lumpsum()
{
	sum = 0;
}

Lumpsum::~Lumpsum()
{
	cout << "sum: " << sum << endl;
}

void Lumpsum::add(int num)
{
	sum += num;
}

void main()
{
	Lumpsum a;
	
	for(int i = 1; i <= 10; i++)
		a.add(i);
}
