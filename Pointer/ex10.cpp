#include <iostream>

using namespace std;


/*
	Function definition.
*/
int sum (int a, int b)
{
 	return (a + b);
}


int (*ptr_sum) (int, int) = &sum;
/*
 	ptr_sum is a pointer to a function taking two ints as arguments and returning an int.
*/



int main ( )
{
	int a, b;
	cout << "Enter two ints (separated by whitespace): ";
	cin >> a >> b;

	
	/*
		Here we check if the function pointer really points to the correct function.
	*/
	if(ptr_sum != &sum)
	{
		cout << "Crazy error";
		//exit (0);
	}

	
	/*
		Here we make use of the function pointer.
	*/
	int result = (*ptr_sum) (a,b);
	cout << "Sum is " << result << "\n";

	return (0);

}
