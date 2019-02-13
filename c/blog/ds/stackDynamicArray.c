#include <stdio.h>
#define NOT_FOUND -1

int top;
int* arr;
int length;

void print()
{
	for (int i = 0; i < top; i++)
		printf("%d, ", arr[i]);
	printf("\n");
}

void push(int data)
{
	if (top >= length) {
		int* newArr = (int*) malloc(sizeof(int) * length * 2);

		for (int i = 0; i < length; i++)
			newArr[i] = arr[i];

		free(arr);
		arr = newArr;
		length = length * 2;
	}
	arr[top++] = data;
}

int pop()
{
	if (empty()) {
		return NOT_FOUND;
	} else if (top < length / 2) {
		int* newArr = (int*) malloc(sizeof(int) * (length / 2));

		for (int i = 0; i < top; i++)
			newArr[i] = arr[i];

		int result = arr[--top];
		free(arr);
		arr = newArr;

		return result;
	} else {
		return arr[--top];
	}
}

int empty()
{
	return top == 0; 
}

int peek()
{
	if (empty())
		return NOT_FOUND;
	return arr[top - 1];
}

int search(int data)
{
	for (int i = 0; i < top; i++) {
		if (data == arr[i])
			return i;
	}

	return NOT_FOUND;
}

void main()
{
	top = 0;
	arr = (int*) malloc(sizeof(int));
	length = 1;

	printf("[before] empty? %s\n", (empty() ? "true" : " false"));

	for (int i = 1; i < 6; i++) {
		push(i);
		printf("peek? %d, search? %d\n", peek(), search(i));
	}
	printf("after push: ");
	print();
	
	printf("empty? %s\n", (empty() ? "true" : " false"));

	for (int i = 1; i < 6; i++)
		printf("pop: %d ", pop());
	
	printf("\n[blank] pop? %d, peek? %d, search? %d\n", pop(), peek(), search(0));

	free(arr);
}
