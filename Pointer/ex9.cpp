 /*
 		Example 8 extended to three-dimensional pointers. No detailed comments included.
*/

#include <iostream>
using namespace std;

int ***ptr;

int main ()
{
	ptr = new int **[2];

	for(int i=0;i<2;i=i+1)
	{
		*(ptr+i) = new int *[3];
	 	for(int j=0;j<3;j=j+1)
		{
			*(*(ptr+i)+j) = new int[4];
	 	}
	}


	/*
		Access the allocated memory.
	*/
	cout << "Summing values within [ ], assigning to pointer and printing. " << "\n";
	for(int i=0;i<2;i=i+1)
	{
		for(int j=0;j<3;j=j+1)
		{
	 		for(int k=0;k<4;k=k+1)
			{
				*(*(*(ptr+i)+j)+k) = i+j+k;
				cout << "ptr[" << i << "][" << j << "]["; cout << k << "] = ";
				cout << *(*(*(ptr+i)+j)+k) << "\n";
			}
		}
	}


	/*
 		Delete the allocated memory.
 	*/
	for(int i=0;i<2;i=i+1)
	{
		for(int j=0;j<3;j=j+1)
		{
	 		delete[] *(*(ptr+i)+j);
	 	}
		delete[] *(ptr+i);
	}
	delete[] ptr;

	return (0);
}
