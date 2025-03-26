#include <stdio.h>
#define MAX 5

struct que {
	int Rear;
	int Front;
	int arr[MAX];
};

void init_que(struct que *q){
	q->Rear = q->Front = -1;
}

void check_add(struct que *q, int val){
	if(q->Rear == MAX-1){
		printf("\noverflow! Queue is  full.");
		return;
	}

	if(q->Rear==-1 && q->Front==-1){
		q->Rear = q->Front = 0;
	}else{
		q->Rear++;
	}

	q->arr[q->Rear] = val;
	printf("\n%d added to the que!", val);
}

void display(struct que *q){
	if(q->Rear==-1 && q->Front==-1){
		printf("underflow!, \nThe que is empty!");
		return;
	}
	printf("\nQueue Elements:\n");
	for(int i=q->Front; i<=q->Rear; i++){
		printf("%d, ",q->arr[i]);
	}
	printf("\n");
}

int main(){

	struct que q;
	init_que(&q);

	check_add(&q, 10);
	check_add(&q, 20);
	check_add(&q, 30);
	check_add(&q, 40);
	check_add(&q, 50);
	check_add(&q, 60);
	check_add(&q, 70);

	display(&q);




	return 0;
}