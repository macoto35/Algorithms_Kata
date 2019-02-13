#include <iostream>
#define NOT_FOUND -1

using namespace std;

class StackDynamicArray {
private:
	int top;
	int* arr;
	int length;
public:
	StackDynamicArray();
	~StackDynamicArray();
	void print();
	void push(int);
	int pop();
	bool empty();
	int peek();
	int search(int);
};

StackDynamicArray::StackDynamicArray()
{
	this->top = 0;
	this->arr = new int[1];
	this->length = 1;
}

StackDynamicArray::~StackDynamicArray()
{
	delete[] this->arr;
}

void StackDynamicArray::print()
{
	for (int i = 0; i < this->top; i++)
		cout << this->arr[i] << ",";
	cout << endl;
}

void StackDynamicArray::push(int data)
{

	if (this->top >= this->length) {
		int* newArr = new int[this->length * 2];

		for (int i = 0; i < this->length; i++)
			newArr[i] = this->arr[i];
		
		delete[] this->arr;
		this->arr = newArr;
		this->length = this->length * 2;
	}

	this->arr[this->top++] = data;
}

int StackDynamicArray::pop()
{
	if (empty()) {
		return NOT_FOUND;
	} else if (this->top < this->length/2) {
		int* newArr = new int[this->length / 2];

		for (int i = 0; i < this->top; i++)
			newArr[i] = this->arr[i];

		int result = this->arr[--this->top];
		delete[] this->arr;
		this->arr = newArr;
		this->length = this->length / 2;

		return result;
	} else {
		return this->arr[--this->top];
	}
}

bool StackDynamicArray::empty()
{
	return this->top == 0;
}

int StackDynamicArray::peek()
{
	if (empty())
		return NOT_FOUND;
	return this->arr[this->top - 1];
}

int StackDynamicArray::search(int data)
{
	for (int i = 0; i < this->top; i++) {
		if (data == this->arr[i])
			return i;
	}
	return NOT_FOUND;
}

void main()
{
	StackDynamicArray stack;

	cout << "[before] empty? " << (stack.empty() ? "true" : " false") << endl;

	for (int i = 1; i < 6; i++) {
		stack.push(i);
		cout << "peek? " << stack.peek() << ", search? " << stack.search(i) << endl;
	}
	cout << "after push: ";
	stack.print();
	
	cout << "empty? " << (stack.empty() ? "true" : " false") << endl;

	for (int i = 1; i < 6; i++)
		cout << "pop: " << stack.pop() << " ";
	
	cout << endl << "[blank] pop? " << stack.pop() << ", peek? " << stack.peek() << ", search? " << stack.search(0) << endl;
}
