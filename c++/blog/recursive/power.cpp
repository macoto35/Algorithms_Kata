#include <iostream>

using namespace std;

int power(int base, int exp)
{
	if (exp == 0)
		return 1;
	return base * power(base, exp-1);
}

int main()
{
	int base;
	cin >> base;

	int exp;
	cin >> exp;

	/* using iteration
	int result = 1;
	for (int i = 0; i < exp; i++)
		result *= base;
	*/

	/* using recursive
	int result = power(base, exp);
	*/

	// effective recursive
	int mid = floor(exp / 2);
	int result = power(base, mid);
	if (exp % 2 == 0)
		result *= result;
	else
		result *= result * base;
	
	cout << base << " ** " << exp << " = " << result << endl;
}
