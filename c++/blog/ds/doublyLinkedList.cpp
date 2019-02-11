#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* prev;
	Node* next;
};

class DoublyLinkedList {
private:
	Node* head;
	Node* tail;
	int length;
	Node* getNode(int);
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	void toString();
	void addFirst(int);
	void addLast(int);
	void addFront(int, int);
	void addBack(int, int);
	bool empty();
	int removeFirst();
	int remove(int);
	int removeLast();
	int size();
	int get(int);
	int indexOf(int);
};

DoublyLinkedList::DoublyLinkedList()
{
	this->head = NULL;
	this->tail = NULL;
	this->length = 0;

	cout << "<Initialization>---";
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* tmp = this->head;
	for (int i = 0; i < this->length; i++) {
		Node* next = tmp->next;
		delete tmp;
		tmp = next;
	}

	this->head = NULL;
	this->tail = NULL;
	this->length = 0;

	cout << "---<Destruction>" << endl;
}

void DoublyLinkedList::toString()
{
	Node* tmp = this->head;
	for (int i = 0; i < this->length; i++) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

void DoublyLinkedList::addFirst(int input)
{
	Node* node = new Node;
	node->data = input;
	node->next = NULL;
	node->prev = NULL;

	if (this->head != NULL) {
		node->next = this->head;
		this->head->prev = node;
	}

	if (this->tail == NULL) {
		this->tail = node;
	}

	this->head = node;
	this->length++;
}

void DoublyLinkedList::addLast(int input)
{
	Node* node = new Node;
	node->data = input;
	node->next = NULL;
	node->prev = NULL;

	if (this->tail != NULL) {
		this->tail->next = node;
		node->prev = this->tail;
	}

	if (this->head == NULL) {
		this->head = node;
	}

	this->tail = node;
	this->length++;
}

Node* DoublyLinkedList::getNode(int idx)
{
	if (idx < this->length/2) {
		Node* tmp = this->head;

		for (int i = 0; i < idx; i++) {
			if (tmp != NULL)
				tmp = tmp->next;
		}

		return tmp;	
	} else {
		Node* tmp = this->tail;

		for (int i = this->length - 1; i > idx; i--) {
			if (tmp != NULL)
				tmp = tmp->prev;
		}

		return tmp;
	}
}

void DoublyLinkedList::addFront(int input, int idx)
{
	if (idx == 0) {
		addFirst(input);
	} else if (idx >= this->length) {
		addLast(input);
	} else {
		Node* newNode = new Node;
		newNode->data = input;
	        newNode->next = NULL;
	        newNode->prev = NULL;
		Node* nextNode = getNode(idx);
		Node* prevNode = nextNode->prev;

		prevNode->next = newNode;
		newNode->prev = prevNode;

		newNode->next = nextNode;
		nextNode->prev = newNode;

		this->length++;
	}
}

void DoublyLinkedList::addBack(int input, int idx)
{
	if (idx >= this->length) {
		addLast(input);
	} else {
		Node* newNode = new Node();
		newNode->data = input;
	        newNode->next = NULL;
	        newNode->prev = NULL;
		Node* prevNode = getNode(idx);
		Node* nextNode = prevNode->next;

		prevNode->next = newNode;
		newNode->prev = prevNode;

		if(nextNode != NULL) {
			newNode->next = nextNode;
			nextNode->prev = newNode;
		} else {
			this->tail = newNode;
		}

		this->length++;
	}
}

bool DoublyLinkedList::empty()
{
	return this->head == NULL;
}

int DoublyLinkedList::removeFirst()
{
	if (empty())
		return -1;

	Node* removeNode = this->head;
	int result = removeNode->data;
	Node* newHead = removeNode->next;

	this->head = newHead;
	if (newHead != NULL)
		newHead->prev = NULL;
	else
		this->tail = NULL;

	delete removeNode;
	this->length--;

	return result;
}

int DoublyLinkedList::remove(int idx)
{
	if (empty() || idx < 0 || idx >= this->length) {
		return -1;
	} else if (idx == 0) {
		return removeFirst();
	} else {
		Node* removeNode = getNode(idx);
		int result = removeNode->data;
		Node* prevNode = removeNode->prev;
		Node* nextNode = removeNode->next;

		if (prevNode != NULL)
			prevNode->next = nextNode;
		else
			this->head = nextNode;

		if(nextNode != NULL)
			nextNode->prev = prevNode;
		else
			this->tail = prevNode;

		delete removeNode;
		this->length--;

		return result;
	}
}

int DoublyLinkedList::removeLast()
{
	if (empty())
		return -1;
	return remove(this->length - 1);
}

int DoublyLinkedList::size()
{
	return this->length;
}

int DoublyLinkedList::get(int idx)
{
	if (empty() || idx < 0 || idx >= this->length)
		return -1;
	return getNode(idx)->data;
}

int DoublyLinkedList::indexOf(int data)
{
	Node* tmp = this->head;

	for (int i = 0; i < this->length; i++) {
		if (tmp->data == data)
			return i;
		tmp = tmp->next;
	}

	return -1;
}

void addFirstTest()
{
	DoublyLinkedList list;

	list.addFirst(1);
	list.addFirst(2);
	list.addFirst(3);
	list.addFirst(4);
	cout << "add first: ";
	list.toString();
}

void addLastTest()
{
	DoublyLinkedList list;

	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	cout << "add last: ";
	list.toString();
}

void addFrontTest()
{
	DoublyLinkedList list;

	list.addFront(1, 0);
	list.addFront(2, 0);
	list.addFront(3, 1);
	list.addFront(4, 2);
	list.addFront(5, 2);
	list.addFront(6, 3);
	cout << "add front: ";
	list.toString();
}

void addBackTest()
{
	DoublyLinkedList list;

	list.addBack(1, 0);
	list.addBack(2, 1);
	list.addBack(3, 1);
	list.addBack(4, 1);
	cout << "add back: ";
	list.toString();
}

void removeFirstTest()
{
	DoublyLinkedList list;
	
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

        cout << "remove first: " << list.removeFirst() << " ";
        cout << list.removeFirst() << " ";
        cout << list.removeFirst() << " ";
        cout << list.removeFirst() << " ";
        cout << list.removeFirst() << " ";
        cout << list.removeFirst() << " ";

	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);
        list.removeFirst();
        list.removeFirst();
        list.addFirst(6);
        list.addBack(7, 2);
        list.removeFirst();
        list.addFront(8, 3);
        list.addLast(9);
	list.toString();
}

void removeTest()
{
	DoublyLinkedList list;
	
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	cout << "remove: " << list.remove(5) << " ";
	cout << list.remove(-1) << " ";
	cout << list.remove(4) << " ";
	cout << list.remove(0) << " ";
	cout << list.remove(1) << " ";
	cout << list.remove(1) << " ";
	cout << list.remove(0);
}

void removeLastTest()
{
	DoublyLinkedList list;
	
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	cout << "remove last: " << list.removeLast() << " ";
	cout << list.removeLast() << " ";
	cout << list.removeLast() << " ";
	cout << list.removeLast() << " ";
	cout << list.removeLast() << " ";
	cout << list.removeLast();
}

void emptyTest()
{
	DoublyLinkedList list;

	cout << "empty: " << (list.empty() ? "true" : "false") << " ";
	list.addLast(1);
	cout << (list.empty() ? "true" : "false");
}

void sizeTest()
{
	DoublyLinkedList list;

	cout << "size: " << list.size() << " ";
	list.addBack(1, 1);
        list.addFirst(2);
        list.addLast(3);
        list.removeFirst();
        list.addFront(4, 2);
        list.addFirst(5);
        list.removeLast();
        list.addLast(6);
        list.addLast(7);
        list.addLast(8);
        list.remove(3);
	list.toString();
	cout << list.size();
}

void getTest()
{
	DoublyLinkedList list;

	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	cout << "get: " << list.get(-1) << " ";
	cout << list.get(0) << " ";
	cout << list.get(1) << " ";
	cout << list.get(2) << " ";
	cout << list.get(3) << " ";
	cout << list.get(4) << " ";
	cout << list.get(5);
}

void indexOfTest()
{
	DoublyLinkedList list;
	
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	cout << "index of: " << list.indexOf(1) << " ";
	cout << list.indexOf(2) << " ";
	cout << list.indexOf(3) << " ";
	cout << list.indexOf(4) << " ";
	cout << list.indexOf(5) << " ";
	cout << list.indexOf(6) << " ";
}

void main()
{
	addFirstTest();
	addLastTest();
	addFrontTest();
	addBackTest();
	removeFirstTest();
	removeTest();
	removeLastTest();
	emptyTest();
	sizeTest();
	getTest();
	indexOfTest();
}
