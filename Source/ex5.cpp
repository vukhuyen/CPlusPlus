#include <iostream>
using namespace std;

int arr[3] = {10, 15, 20};

int *ptr = new int[3];

int main ()
{
	*(ptr+0) = 2;
	ptr[1] = 4;
	*(ptr+2) = 6;
	/*
		Shows how to access pointers using either array or pointer notation
	*/

	/*
		In the same way, an array can also be accessed using pointer notation.
	*/
	cout << "arr[0] using array notation = " << arr[0] << "\n";
	cout << "arr[1] using pointer notation = " << *(arr+1) << "\n";

	/*
		Now we will access the base address of the array that the pointer points to.
	*/
	cout << "Base address of array ptr points to: " << ptr << "\n";
	/*
		Now we will access the base address of the array arr
	*/
	cout << "Base address of array arr is: " << arr << "\n";
	
	/*
		The above example highlights the close linkages between pointer and array notations in C++
	*/

	return (0);
}
