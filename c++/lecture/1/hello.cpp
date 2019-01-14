#include <iostream>

using namespace std;

/*
https://m.post.naver.com/viewer/postView.nhn?volumeNo=16964&memberNo=37462&clipNo=0

cl /EHsc a.cpp
-> /EHsc: enable c++ exception handling
*/
int main(void)
{
	int a, b;

	cout << "enter a first interger!";
	cin >> a;

	cout << "enter a second interger!";
	cin >> b;

	cout << a << " + " << b << " = " << a+b << endl;

	return 0;
}
