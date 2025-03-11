#include <stdio.h> 
int main() {
//write a C program that accepts a group N domestic animals and a group 
//of X wild animals. Your program should print N+X animals after entering 
//each group 

int N,X;

printf("please enter the number of domestic animals: ");
scanf("%d",&N);
char domestic_animal[N][30];

printf("please enter the number of wild animals: ");
scanf("%d", &X);
char wild_animal[X][30];

printf("please list the domestic animals:\n");
for(int i=0; i<N; i++){
	printf("animal%d ",i + 1);
	scanf("%s", domestic_animal[i]);
}

printf("please list the wild animals:\n ");
for(int i=0; i<X; i++){
	printf("animal%d ",i + 1);
	scanf("%s", wild_animal[i]);
}

printf("\nAll animals incude: ");
for (int i=0; i<N; i++){
	printf("%s\n", domestic_animal[i]);
}
for (int i=0; i<X; i++){
	printf("%s\n", wild_animal[i]);
}

	return 0;
}