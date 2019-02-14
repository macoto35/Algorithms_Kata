#include <stdio.h>
#define size 5

int arr[size];
int read = -1;
int write = -1;

int empty()
{
	return read == -1;
}

void print()
{
	if (empty())
		return;
	int i;
	for (i = read; i != write; i = (i + 1) % size)
		printf("%d ", arr[i]);
	printf("%d\n", arr[i]);
}

int full()
{
	return (write + 1) % size == read;
}

void enqueue(int data)
{
	if (full()) {
		fprintf(stderr, "[error] Array Index Out of Bounds!\n");
		return;
	}

	if (read == -1)
		read = 0;

	write = (write + 1) % size;
	arr[write] = data;
}

int dequeue()
{
	if (empty())
		return -1;

	int result = arr[read];

	if (read == write)
		read = write = -1;
	else
		read = (read + 1) % size;

	return result;
}

void main()
{
	for (int i = 1; i < 6; i++)
		enqueue(i);
	print();
	enqueue(6);

	printf("dequeue: ");
	for (int i = 1; i < 6; i++)
		printf("%d ", dequeue());

	enqueue(1);
        enqueue(2);
        enqueue(3);
        printf("\ndequeue: %d\n", dequeue());
        printf("dequeue: %d\n", dequeue());
        enqueue(4);
        enqueue(5);
        enqueue(6);
        enqueue(7);

	enqueue(8);

        printf("dequeue: %d\n", dequeue());
        enqueue(8);

	print();
}
