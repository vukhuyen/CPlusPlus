#include <iostream>

using namespace std;



int sum (int a, int b)
{
	return (a + b);
}
typedef int (*ptr_sum_type)(int, int);



int main ( )
{
	int a, b;

	
	/*
		Now we create an object (pointer) using the typedef declaration made earlier
	*/
	ptr_sum_type ptr_sum= &sum;

	
	cout << "Enter two ints (separated by whitespace): ";
	cin >> a >> b;

	
	/*
		Here we make use of the function pointer.
	*/
	int result = (*ptr_sum) (a,b);
	cout << "Sum is " << result << "\n";

	
	return (0);
}
