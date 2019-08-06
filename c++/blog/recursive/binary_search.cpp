#include <iostream>

using namespace std;

bool binary_search(int st, int ed, int target)
{
	if (st > ed)
		return false;

	int mid = floor((st + ed) / 2);

	if (target == mid) {
		return true;
	} else if (target < mid) {
		return binary_search(st, mid - 1, target);
	} else {
		return binary_search(mid + 1, ed, target);
	}
}

int main()
{
	int st;
	cout << "please enter start point: ";
	cin >> st;

	int ed;
	cout << "please enter end point: ";
	cin >> ed;

	int target;
	cout << "please enter target value: ";
	cin >> target;

	cout << target << " is " << (binary_search(st, ed, target)? "exist" : "not exist") << endl;
}
