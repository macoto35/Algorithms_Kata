#include <iostream>

using namespace std;

/*
Access Specifier

specifier | same class | derived(child) class | outside the class |
private   | Y          | N                    | N                 |
protected | Y          | Y                    | N                 |
public    | Y          | Y                    | Y                 |

*/
class Number {
	private:
		int num;
	public:
		void input(int data);
		void print();
};

void Number::input(int data)
{
	num = data;
}

void Number::print()
{
	cout << num << endl;
}

int main(void)
{
	Number n;
	
	/* cannot acess private member
	 * n.num = 3;
	 * cout << n.num;
	*/

	n.input(3);
	n.print();

	return 0;
}
