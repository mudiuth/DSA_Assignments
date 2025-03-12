/*An algorith to delet an element from an array of strings

this kind of algorithm iterates through teh array looking for the element to know if it exists.
After the location of the element, it is deleted from the array 

step 1: start
step 2: take the array, its size and the index to delet as an input
step 3: check the validity of the index in the bound (0 - (size-1))
step 4: if valid, shift al the elements after the index one position to the left
step 5: decreaze the array size by 1 
step 6: if invalid, print an error message 
step 7: stop */

//example of the code 

#include <stdio.h>
#include <string.h>
int main(){
	char arr[5][10]={"cow","goat","cat","rat","dog"};
	int _size = sizeof(arr) / sizeof(arr[0]);
	

	printf("below are the available animals:");
	for(int i=0; i<_size; i++){
		printf("\n%d. %s", i + 1, arr[i]);
	}
	int _no;
	printf("\nplease enter the animal u want to remove (enter its corresponding number): ");
	scanf("%d", &_no);

	if (_no > 0 && _no <= _size){
		for(int i = _no-1; i < _size-1; i++){
			strcpy(arr[i], arr[i+1]);	//shift an element to the left
		}_size--;
	}else{
		printf("incorrect number entered");
	}

printf("%s is deleted",arr[_no - 1]);
for (int i=0; i<_size; i++ ){
	printf("\n%d. %s", i + 1, arr[i]);
}


	return 0;
}