/* an algorithm to call an element from an array after locating it.

step 1: start 
step 2: save an array, its size and index as input 
step 3: check if the array is available in the bound (0 - (size -1))
step 4: if the element is available, call it with its index 
step 5: if the element is not available, return an error.
step 6: end 

this algorith will tell a code to declare an array eg int nums [5] = {1,2,3,4,5}; and then store them. then after itll again accept an index as an input.
it will then check the index entered and if there's an element in the corresponding index, itll print it. but when the index entered is incorrect, itll then print an error message  

below is an example of a code that can do that */

#include <stdio.h>
int main(){
	int nums[5]={1,2,3,4,5};
	int _size = sizeof(nums) / sizeof(nums[0]);
	int index;
	printf("please enter the index of the number to be printed: ");
	scanf("%d", &index);

	//for (int i=0; i<=_size; i++){
	if (index>=0 && index<_size){
	printf("\nthe number at %d is %d",index, nums[index]);
	}else{
		printf("\nindex entered is out of bounds of the available array");
	}
	//}
	


	return 0;
} 