#include <iostream>

using namespace std;

/*
  Function declaration.
*/
int * sum (int *i, int *j);

/*
   Function definition.
*/
int * sum (int *i, int *j)
{
 	int *result = new int;
	 
 	*result = *i + *j;

	return (result);
	/*
	 	The return value from function is equivalent to:
			int *unnamed = result;
	*/
}


int main ()
{
	int p = 10, q = 20;

	int *r = sum(&p, &q);
	/*
		The pointer r stores the base address of the memory allocated with new operator in the function sum. 
	*/

	cout << "The sum is " << *r << "\n";

	return (0);
	
	/*
		Since memory is not being deleted with delete operator, a memory leak is created. Never do it in practice.
	*/
	
}


