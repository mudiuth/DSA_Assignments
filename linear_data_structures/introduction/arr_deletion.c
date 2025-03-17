/*Algorithm for deleting a element from an array
● 1. Start
● 2. Set upper_bound = upper_bound - 1
● 3. Stop*/

#include <stdio.h>
int main(){

	int arr[5]={1,2,3,4,5};
	int _no;
	int _size = sizeof(arr)/sizeof(arr[0]);

	printf("please enter the index u want to delet: ");
	scanf("%d", &_no);
	if (_no>=0 && _no<_size){
		for (int i=_no; i<_size; i++){
			arr[i]=arr[i+1];
			//_size=_size-1;
		}_size--;

		for (int i=0; i<_size; i++){
			printf("%d ",arr[i]);
		}
		
	}else{
		printf("wrong index entered!");
	}
		
	



	return 0;
}