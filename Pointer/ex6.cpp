#include <iostream>

using namespace std;

int **ptr2;
int *ptr;
int i = 10;

int main ()
{
	/*
		What does *ptr print now?
 	*/
	ptr = &i;

	/*
		Now we assign the base address of ptr (the pointer itself, not what it points to) to ptr2
	*/
	ptr2 = &ptr;

	/*
		The same variable can be accessed through multi-dimensional pointer also
	*/
	cout << "Accessing i through i: " << i << "\n";
	cout << "Accessing i through ptr: " << *ptr << "\n";
	cout << "Accessing i through ptr2: " << **ptr2 << "\n";

	return (0);
}
