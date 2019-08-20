#include <iostream>

using namespace std;

void moveSingleDisk(int diskNum, char source, char dest)
{
	cout << diskNum << ": " << source << "->" << dest << endl;
}

void moveTower(int n, char source, char dest, char tmp)
{
	if (n ==0)
		return;
	moveTower(n-1, source, tmp, dest);
	moveSingleDisk(n, source, dest);
	moveTower(n-1, tmp, dest, source);
}

void main()
{
	int n;
	cin >> n;
	moveTower(n, 'A', 'B', 'C');
}
