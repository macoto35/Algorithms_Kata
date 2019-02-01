#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

void main()
{
	Node a, b;
	a.data = 1;
	b.data = 2;
	a.next = &b;
	cout << a.data << " / " << a.next->data << endl;

	Node* pa = new Node;
	Node* pb = new Node;
	pa->data = 3;
	pb->data = 4;
	pa->next = pb;

	cout << pa->data << " / " << pa->next->data << endl;
	
	delete pa;
	delete pb;
}
