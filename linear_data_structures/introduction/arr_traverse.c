/*
Algorithm for array Traversal
● Step 1. Start
● Step 2. [INITIALIZATION] Set I lower bound
● Step 3. Repeat steps 3to 4 while I< = upper bound
● Step 4. Apply process to A [I]
● Step 5. Set I = I + 1
● [End loop]
● Step 6: Exit*/

#include <stdio.h>
int main(){

     int arr[5]={1,2,3,4,5};

	for (int i=0; i<5; i++){
		printf("\nthe vaue of n is %d",arr[i]);
	}


	return 0;
}