/*this kind of time complexity happens when the time required to run the algorithm
to completion is actually directly proportional to the square of the number of inputs
this most times happens in nested loops when functions are calling each other

below is the algorithm of such 
step1: start 
step2: take an input as an interger call it _num
step3: for i is 0 to i is _num do 
step4: call another loop 
step5: for i=j and j is less than _num, add j to sum 
step6: return final sum 
step7: stop */

//below is an example of the code in c 

#include <stdio.h>
int main(){

	int _num;
	printf("please enter the desire numbe: ");
	scanf("%d",&_num);

	for (int i=0; i<=_num;i++){
		for(int j=i+2; j<=_num; j++){
			printf("\n%d",j);
		}
	}


	return 0;
}