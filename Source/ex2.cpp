#include <iostream>

using namespace std;

int main ()
{
	int i = 10;
	int *x = &i;
	int *y;
	/*
		x stores the address of variable i. Pointer assignment could also be done as:
	*/
	y = &i;

	cout << "The pointer x is stored at the memory address "<< &x << "\n";
	cout << "The pointer x stores the memory address of i: " << x << "\n";
	/*
		Contrast the difference between the memory address of the pointer and the memory address it stores.
	*/

	cout << "The value of i accessed through pointer x is " << *x << "\n";
	

	/*
		Now we manipulate the value of i using pointer x.
	*/
	*x = *x + 1; /* increments i by 1 */

	cout << "i (through pointer) = " << *x << " which equals i (direct access) " << i << "\n";
	/*
		A pointer does not create a copy of the variable it points to.
	*/

	cout << "The memory allocated to the pointer x is " << sizeof(x) << " bytes.\n";
	return (0);
}
