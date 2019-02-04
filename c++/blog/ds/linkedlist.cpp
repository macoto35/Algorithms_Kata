#include <iostream>

using namespace std;

class Node {
	public:
		int data;
		Node* next;
		Node(int, Node*);
};

class LinkedList {
	private:
		Node* head = NULL;
		Node* tail = NULL;
		int length = 0;
		Node* getNode(int);
	public:
		void toString();
		void removeAll();

		void addFirst(int);
		void addLast(int);
		void addFront(int, int);
		void addBack(int, int);
};

Node::Node(int d, Node* n)
{
	this->data = d;
	this->next = n;
}

void LinkedList::toString()
{
	Node* tmp = this->head;
	for (int i = 0; i < length; i++) {
		cout << tmp->data << ", ";
		tmp = tmp->next;
	}
	cout << endl;
}

void LinkedList::removeAll()
{
	Node* tmp = this->head;
	Node* next;
	for (int i = 0; i < length; i++) {
		next = tmp->next;
		delete tmp;
		tmp = next;
	}
	this->length = 0;
	this->head = NULL;
	this->tail = NULL;
}

void LinkedList::addFirst(int input)
{
	Node* node = new Node(input, NULL);

	if (this->head != NULL)
		node->next = this->head;

	if (this->tail == NULL)
		this->tail = node;

	this->head = node;
	this->length++;
}

void LinkedList::addLast(int input)
{
	Node* node = new Node(input, NULL);

	if (this->tail != NULL)
		this->tail->next = node;

	if (this->head == NULL)
		this->head = node;

	this->tail = node;
	this->length++;
}

Node* LinkedList::getNode(int idx)
{
	Node* tmp = this->head;
	for (int i = 0; i < idx; i++) {
		if (tmp->next != NULL) {
			tmp = tmp->next;
		}
	}

	return tmp;
}

void LinkedList::addFront(int input, int idx)
{
	if (idx == 0) {
		this->addFirst(input);
	} else if (idx >= this->length) {
		this->addLast(input);
	} else {
		Node* prev = this->getNode(idx - 1);
		Node* node = new Node(input, NULL);

		node->next = prev->next;
		prev->next = node;
		this->length++;
	}
}

void LinkedList::addBack(int input, int idx)
{
	if (idx >= this->length) {
		this->addLast(input);
	} else {
		Node* current = this->getNode(idx);
		Node* node = new Node(input, NULL);

		node->next = current->next;
		current->next = node;

		if (node->next == NULL)
			this->tail = node;

		this->length++;
	}
}

void main()
{
	LinkedList list;
	
	// add first - 4,3,2,1
	list.addFirst(1);
	list.addFirst(2);
	list.addFirst(3);
	list.addFirst(4);
	cout << "add first: ";
	list.toString();

	list.removeAll();

	// add last - 1,2,3,4
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	cout << "add last: ";
	list.toString();

	list.removeAll();

	// add front - 1,3,4,2
	list.addFront(1, 0);
	list.addFront(2, 1);
	list.addFront(3, 1);
	list.addFront(4, 2);
	cout << "add front: ";
	list.toString();

	list.removeAll();

	// add back - 1,2,4,3
	list.addBack(1, 0);
	list.addBack(2, 1);
	list.addBack(3, 1);
	list.addBack(4, 1);
	cout << "add back: ";
	list.toString();

	list.removeAll();
}
