/*Algorithm for inserting a element to an existing array
● Step 1. Start
● Step 2. Set upper_bound = upper_bound+1
● Step 3. Set A[upper_bound] = val
● Step 4. Stop*/

#include <stdio.h>
int main(){
	int arr[6]={1,2,3,4,5};
	int _size= sizeof(arr)/sizeof(arr[0]);

	arr[_size-1]=6;
	//_size++;

		for (int j=0; j<_size; j++){
			printf("%d ",arr[j]);
		}
	printf("\n");	
	


	return 0;
}