#include <iostream>
#define size 5

using namespace std;

class QueueArray {
private:
	int arr[size];
	int read = -1;
	int write = -1;
public:
	void print();
	bool full();
	bool empty();
	void enqueue(int);
	int dequeue();
};

void QueueArray::print()
{
	if (this->empty())
		return;

	int i;
	for (i = this->read; i != this->write; i = (i + 1) % size)
		cout << this->arr[i] << " ";
	cout << this->arr[i] << endl;
}

bool QueueArray::full()
{
	return (this->write + 1) % size == this->read;
}

bool QueueArray::empty()
{
	return this->read == -1;
}

void QueueArray::enqueue(int data)
{
	if (this->full())
		throw "Array Index Out of Bounds!";

	if (this->read == -1)
		this->read = 0;

	this->write = (this->write + 1) % size;
	this->arr[this->write] = data;
}

int QueueArray::dequeue()
{
	if (this->empty())
		return NULL;

	int result = this->arr[this->read];

	if (this->read == this->write)
		this->read = this->write = -1;
	else
		this->read = (this->read + 1) % size;

	return result;
}

void main()
{
	QueueArray queue;

	for (int i = 1; i < 6; i++)
		queue.enqueue(i);
	queue.print();

	try {
		queue.enqueue(6);
	} catch (char* msg) {
		cout << "[error!] " << msg << endl;
	}

	cout << "dequeue: ";
	for (int i = 1; i < 6; i++)
		cout << queue.dequeue() << " ";

	queue.enqueue(1);
        queue.enqueue(2);
        queue.enqueue(3);
        cout << endl << "dequeue: " << queue.dequeue() << endl;
        cout << "dequeue: " << queue.dequeue() << endl;
        queue.enqueue(4);
        queue.enqueue(5);
        queue.enqueue(6);
        queue.enqueue(7);

	try {
		queue.enqueue(8);
	} catch (char* msg) {
		cout << "[error!] " << msg << endl;
	}

        cout << "dequeue: " << queue.dequeue() << endl;
        queue.enqueue(8);

	queue.print();
}
