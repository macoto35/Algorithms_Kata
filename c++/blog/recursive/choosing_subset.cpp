#include <iostream>

using namespace std;

int nck(int n, int k)
{
	cout << n << " / " << k << endl;
	if (n == k || k == 0)
		return 1;
	return nck(n-1, k-1) + nck(n-1, k);
}

int main()
{
	int n;
	cout << "please enter N: ";
	cin >> n;

	int k;
	cout << "Please enter k: ";
	cin >> k;

	cout << nck(n, k) << endl;
}
