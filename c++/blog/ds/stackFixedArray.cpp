#include <iostream>

using namespace std;

class StackFixedArray {
private:
	int top;
	int arr[4];
public:
	StackFixedArray();
	void push(int);
	int pop();
	bool empty();
	int peek();
	int search(int);
};

StackFixedArray::StackFixedArray()
{
	top = 0;
	for (int i = 0; i < 4; i++)
		arr[i] = -1;
}

void StackFixedArray::push(int data)
{
	int length = sizeof(arr) / sizeof(int);
	if (top >= length)
		throw "Array Out of Index!";
	arr[top++] = data;
}

bool StackFixedArray::empty()
{
	return top == 0;
}

int StackFixedArray::pop()
{
	if (empty())
		return -1;
	return arr[--top];
}

int StackFixedArray::peek()
{
	if (empty())
		return -1;
	return arr[top - 1];
}

int StackFixedArray::search(int data)
{
	for (int i = 0; i < top; i++) {
		if (data == arr[i])
			return i;
	}
	return -1;
}

void main()
{
	StackFixedArray stack;

	cout << "[before] empty? " << (stack.empty() ? "true" : "false") << endl;
	for (int i = 1; i < 5; i++)
		stack.push(i);
	try {
		stack.push(5);
	} catch (const char* msg) {
		cout << msg << endl;
	}
	
	cout << "[after] empty? " << (stack.empty() ? "true" : "false") << endl;

	for (int i = 1; i < 5; i++) {
		cout << "peek: " << stack.peek();
		cout << ", search: " << stack.search(i) << endl;
	}
	
	cout << "pop: ";
	for (int i = 1; i < 5; i++)
		cout << stack.pop() << ", ";

	cout << endl << "peek: " << stack.peek();
	cout << ", search: " << stack.search(5);
	cout << ", pop: " << stack.pop() << endl;
}
