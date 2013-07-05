#include <iostream>

using namespace std;

int main ( )
{

 	int i = 10;

 	cout << "The value of variable i is " << i << "\n";

	cout << "The memory address of i is " << &i << "\n";
	/*
		Prints the memory address in hexadecimal format.
	*/

	cout << "The value of variable i using * operator is " << *(&i) << "\n";
	/*
		The * operator gives the value when provided with a memory address. Note that the data type is inferred from the variable name.
	*/

	return (0);
}
