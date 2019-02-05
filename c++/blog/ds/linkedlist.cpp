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
		void tearDown();

		void addFirst(int);
		void addLast(int);
		void addFront(int, int);
		void addBack(int, int);
		int removeFirst();
		int remove(int);
		int removeLast();
		bool empty();
		int size();
		int get(int);
		int indexOf(int);
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

void LinkedList::tearDown()
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

int LinkedList::removeFirst()
{
	if (this->empty()) {
		return -1;
	} else {
		Node* del = this->head;
		int result = del->data;

		this->head = del->next;
		if (this->head == NULL)
			this->tail = NULL;

		delete del;
		this->length--;

		return result;
	}
}

int LinkedList::remove(int idx)
{
	if (idx == 0) {
		return this->removeFirst();
	} else if (idx >= this->length) {
		return -1;
	} else {
		Node* prev = this->getNode(idx - 1);
		Node* del = prev->next;
		int result = del->data;

		prev->next = del->next;
		if (prev->next == NULL)
			this->tail = prev;

		delete del;
		this->length--;

		return result;
	}
}

int LinkedList::removeLast()
{
	if (empty())
		return -1;
	return this->remove(this->length - 1);
}

bool LinkedList::empty()
{
	return this->head == NULL;
}

int LinkedList::size()
{
	return this->length;
}

int LinkedList::get(int idx)
{
	if (idx < 0 || idx >= this->length)
		return -1;
	return this->getNode(idx)->data;
}

int LinkedList::indexOf(int data)
{
	Node* tmp = this->head;
	for (int i = 0; i < this->length; i++) {
		if (tmp->data == data)
			return i;
		tmp = tmp->next;
	}
	return -1;
}

void addFirstTest(LinkedList list)
{
	// add first - 4,3,2,1
	list.addFirst(1);
	list.addFirst(2);
	list.addFirst(3);
	list.addFirst(4);
	cout << "add first: ";
	list.toString();

	list.tearDown();
}

void addLastTest(LinkedList list)
{
	// add last - 1,2,3,4
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	cout << "add last: ";
	list.toString();

	list.tearDown();
}

void addFrontTest(LinkedList list)
{
	// add front - 1,3,4,2
	list.addFront(1, 0);
	list.addFront(2, 1);
	list.addFront(3, 1);
	list.addFront(4, 2);
	cout << "add front: ";
	list.toString();

	list.tearDown();
}

void addBackTest(LinkedList list)
{
	// add back - 1,2,4,3
	list.addBack(1, 0);
	list.addBack(2, 1);
	list.addBack(3, 1);
	list.addBack(4, 1);
	cout << "add back: ";
	list.toString();

	list.tearDown();
}

void removeFirstTest(LinkedList list)
{
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	printf("remove first: %d ", list.removeFirst());
	printf("%d ", list.removeFirst());
	printf("%d ", list.removeFirst());
	printf("%d ", list.removeFirst());
	printf("%d ", list.removeFirst());
	printf("%d\n", list.removeFirst());

	list.tearDown();
}

void removeTest(LinkedList list)
{
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	printf("remove: %d ", list.remove(5));
	printf("%d ", list.remove(4));
	printf("%d ", list.remove(0));
	printf("%d ", list.remove(1));
	printf("%d ", list.remove(1));
	printf("%d\n", list.remove(0));

	list.tearDown();
}

void removeLastTest(LinkedList list)
{
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	printf("remove last: %d ", list.removeLast());
	printf("%d ", list.removeLast());
	printf("%d ", list.removeLast());
	printf("%d ", list.removeLast());
	printf("%d ", list.removeLast());
	printf("%d\n", list.removeLast());

	list.tearDown();
}

void emptyTest(LinkedList list)
{
	printf("empty: %s ", list.empty()? "true" : "false");

	list.addLast(1);
	printf("%s\n", list.empty()? "true" : "false");

	list.tearDown();
}

void sizeTest(LinkedList list)
{
	printf("size: %d ", list.size());

	list.addLast(1);
	printf("%d\n", list.size());

	list.tearDown();
}

void getTest(LinkedList list)
{
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	printf("get: %d ", list.get(-1));
	printf("%d ", list.get(0));
	printf("%d ", list.get(1));
	printf("%d ", list.get(2));
	printf("%d ", list.get(3));
	printf("%d ", list.get(4));
	printf("%d\n", list.get(5));

	list.tearDown();
}

void indexOfTest(LinkedList list)
{
	list.addLast(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);
	list.addLast(5);

	printf("index of: %d ", list.indexOf(1));
	printf("%d ", list.indexOf(2));
	printf("%d ", list.indexOf(3));
	printf("%d ", list.indexOf(4));
	printf("%d ", list.indexOf(5));
	printf("%d\n", list.indexOf(6));

	list.tearDown();
}

void main()
{
	LinkedList list;
	
        addFirstTest(list);
	addLastTest(list);
	addFrontTest(list);
	addBackTest(list);

	removeFirstTest(list);
	removeTest(list);
	removeLastTest(list);

	emptyTest(list);
	sizeTest(list);
	getTest(list);
	indexOfTest(list);
}
