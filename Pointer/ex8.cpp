#include <iostream>

using namespace std;

int **ptr;

int main ()
{
	ptr = new int *[3];
	/*
		Statement is read as: "ptr stores the base address of an array of three pointers to an int or int array". More on this in section on "Deciphering Pointer Declarations".
	*/

	
	for(int i=0;i<3;i=i+1)
	{
	 	*(ptr + i) = new int[4];
	}
	/*
		The above loop can also be replaced with:
			ptr = new int[3][4]; 
	*/

	
	/*
	 	Now we can manipulate the allocated memory.
 	*/
 	for(int i=0;i<3;i=i+1)
 	{
		for(int j=0;j<4;j=j+1)
	 	{
			*(*(ptr+i)+j) = i + j;
			/*
				This can also be written as:
					ptr[i][j] = i + j;
			*/

			cout << "ptr[" << i << "][" << j << "] = " << ptr[i][j]; cout << "\n";
		}
	}


 	/*
		Free the allocated memory now. The number of delete statements must match number of new statements. This is merely a copy-paste of the previous section, where new operator has been replaced with delete.
	*/
	for(int i=0;i<3;i=i+1)
	{
		delete[] *(ptr+i);
	}
	delete[] ptr;

	return (0);
}
