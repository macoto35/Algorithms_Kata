#include <iostream>

using namespace std;

void main()
{
	int* arr;
	int size;

	cout << "enter the array size: ";
	cin >> size;

	arr = new int[size]; // same as 'arr = (int*) malloc(sizeof(int) * size)'
	cout << "array has been created with " << size << " elements" << endl;

	/*
            delete : release single element
            delete[] : releases all
	*/
	delete[] arr; // same as 'free(arr)'
	cout << "deleted array from the memory" << endl;
}
