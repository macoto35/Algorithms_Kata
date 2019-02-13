#include <stdio.h>

int top = 0;
int arr[] = {-1, -1, -1, -1};

int empty()
{
	return top == 0;
}

void push(int data)
{
	int length = sizeof(arr) / sizeof(int);
	
	if (top >= length) {
		fprintf(stderr, "Array Out of Index Error!\n");
		return;
	}
	
	arr[top++] = data;
}

int peek()
{
	if (empty())
		return -1;
	return arr[top - 1];
}

int search(int data)
{
	for (int i = 0; i < 4; i++) {
		if (data == arr[i])
			return i;
	}
	return -1;
}

int pop()
{
	if (empty())
		return -1;
	return arr[--top];
}

void main()
{
	printf("[before] empty? %s\n", (empty()? "true" : "false"));
	
	for (int i = 1; i < 5; i++)
		push(i);
	push(5);

	printf("[after] empty? %s\n", (empty()? "true" : "false"));

	for (int i = 1; i < 5; i++) {
		printf("peek: %d, search: %d\n", peek(), search(i));
	}

	printf("pop: ");
	for (int i = 1; i < 5; i++)
		printf("%d, ", pop());

	printf("\npeek: %d, search: %d, pop: %d\n", peek(), search(5), pop());
}
