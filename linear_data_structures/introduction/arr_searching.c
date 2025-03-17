/*Algorithm for searching an element in an array
● Step 1: Start
● Step 2: [INITIALIZATION] Set I = 0, target element as X
● Step 3: Repeat steps 4 and 5 while I < N (where N is the size of the array)
● Step 4: If A[I] == X, return index I and go to Step 6
● Step 5: Set I = I + 1
[End loop]
● Step 6: If no element is found, return -1
● Step 7: Exit*/

#include <stdio.h>
int main(){
	int arr[5]={1,2,3,4,5};
	int _no;

	printf("please enter the search index below:\n");
	scanf("%d", &_no);

	//for (int i=0; i<5; i++){
		//if(arr[i]==_no)
		if(_no>=0 && _no<5){
			printf("\nthe number with index %d is %d",_no, arr[_no]);
		}else {
			printf("\nthe entered index is incorrect or out of bound");
		}

	

	return 0;
}