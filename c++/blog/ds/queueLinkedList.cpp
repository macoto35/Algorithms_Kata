#include <iostream>

using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int);
};

Node::Node(int data) {
	this->data = data;
	this->next = NULL;
}

class QueueLinkedList {
private:
	Node* head = NULL;
	Node* tail = NULL;
public:
	~QueueLinkedList();
	void print();
	bool empty();
	void enqueue(int);
	int dequeue();
};

QueueLinkedList::~QueueLinkedList()
{
	Node* tmp;
	while (this->head != NULL) {
		tmp = this->head;
		this->head = this->head->next;
		cout << "delete: " << tmp->data << endl;
		delete tmp;
	}
	this->tail = NULL;
}

void QueueLinkedList::print()
{
	Node* tmp = this->head;
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

bool QueueLinkedList::empty()
{
	return this->head == NULL;
}

void QueueLinkedList::enqueue(int data)
{
	// addLast
	Node* node = new Node(data);

	if (this->tail != NULL)
		this->tail->next = node;

	if (this->head == NULL)
		this->head = node;

	this->tail = node;
}

int QueueLinkedList::dequeue()
{
	//removeFirst
	if (this->empty())
		return -1;

	Node* del = this->head;
	int result = del->data;
	Node* newHead = del->next;

	this->head = newHead;

	if (newHead == NULL)
		this->tail = NULL;

	delete del;
	return result;
}

void main()
{
	QueueLinkedList queue;

	for (int i = 1; i <= 10; i++)
		queue.enqueue(i);
	
	cout << "[enqueue] ";
	queue.print();
	
	cout << "[dequeue]: ";
	for (int i = 1; i <= 10; i++)
		cout << queue.dequeue() << " ";
	cout << endl;

	cout << "[empty queue] " << queue.dequeue() << endl;
}
