#include <stdio.h> 
#include <string.h>
int main() {
/*write a C program that accepts a group N domestic animals and a group 
of X wild animals. Your program should print N+X animals after entering 
each group*/ 

int N,X;

printf("please enter the number of domestic animals: ");
scanf("%d",&N);
char domestic_animal[N][30];

printf("please enter the number of wild animals: ");
scanf("%d", &X);
char wild_animal[X][30];

char All_animals[N + X][30];

printf("please list the domestic animals:\n");
for(int i=0; i<N; i++){
	printf("animal%d ",i + 1);
	scanf("%s", domestic_animal[i]);
	strcpy(All_animals[i], domestic_animal[i]); //we are copying the domestic animals into all animals
}

printf("please list the wild animals:\n ");
for(int i=0; i<X; i++){
	printf("animal%d ",i + 1);
	scanf("%s", wild_animal[i]);
	strcpy(All_animals[N + i], wild_animal[i]); //we are copying the wild animals into all animals 
}

printf("\nAll animals incude:\n");
for (int i=0; i<(N + X); i++){
	printf("%s\n", All_animals[i]);
}

	return 0;
}
