#include <iostream>
#define NOT_FOUND -1

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int);
};

Node::Node(int data)
{
	this->data = data;
	next = NULL;
}

class StackLinkedList {
private:
	Node* head = NULL;
public:
	~StackLinkedList();
	void print();
	void push(int);
	int pop();
	bool empty();
	int peek();
	int search(int);
};

StackLinkedList::~StackLinkedList()
{
	cout << "enter destructor!" << endl;
	Node* tmp;

	while(head != NULL) {
		tmp = head;
		head = head->next;
		cout << "delete " << tmp->data << endl;
		delete tmp;
	}
}

void StackLinkedList::print()
{
	Node* tmp = this->head;

	while(tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

// addFirst
void StackLinkedList::push(int data)
{
	Node* node = new Node(data);

	node->next = this->head;
	this->head = node;
}

// removeFirst
int StackLinkedList::pop()
{
	if (this->empty()) {
		return NOT_FOUND;
	} else {
		Node* del = this->head;
		int result = del->data;
		Node* newHead = del->next;

		this->head = newHead;
		delete del;

		return result;
	}
}

bool StackLinkedList::empty()
{
	return this->head == NULL;
}

int StackLinkedList::peek()
{
	if (this->empty())
		return NOT_FOUND;
	return this->head->data;
}

int StackLinkedList::search(int data)
{
	Node* tmp = this->head;
	int idx = 0;

	while(tmp != NULL) {
		if (data == tmp->data)
			return idx;
		idx++;
		tmp = tmp->next;
	}

	return NOT_FOUND;
}

void main()
{
	StackLinkedList stack;

	cout << "[before] empty? " << (stack.empty() ? "true" : " false") << endl;

	for (int i = 1; i < 6; i++) {
		stack.push(i);
		cout << i << ", peek? " << stack.peek() << endl;
	}
    for (int i = 1; i < 6; i++)
		cout << i << ", search? " << stack.search(i) << endl;
	cout << "after push: ";
	stack.print();
	
	cout << "empty? " << (stack.empty() ? "true" : " false") << endl;

	for (int i = 1; i < 6; i++)
		cout << "pop: " << stack.pop() << " ";
	
	cout << endl << "[blank] pop? " << stack.pop() << ", peek? " << stack.peek() << ", search? " << stack.search(0) << endl;
}
