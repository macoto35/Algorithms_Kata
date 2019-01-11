#include <iostream>

using namespace std;

class LumpSum {
	private:
		int sum;
	public:
		void init(void);
		void add(int data);
		void print(void);
};

void LumpSum::init(void)
{
	sum = 0;
}

void LumpSum::add(int data)
{
	sum += data;
}

void LumpSum::print(void)
{
	cout << "sum: " << sum << endl;
}

int main(void)
{
	LumpSum ls;

	ls.init();
	
	for(int i = 1; i <= 10; i++)
		ls.add(i);

	ls.print();

	return 0;
}
