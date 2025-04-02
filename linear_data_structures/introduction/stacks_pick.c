#include <stdio.h>
#include <string.h>
#define MAX 5

struct stack {
	int top;
	char arr[MAX][20];//array to store the elements 5 strins with a max of 19 characters each 
};

void init_stack (struct stack *s){
	s->top=-1;
}

void check_Push(struct stack *s, const char *friends){  //a function that is made to check if the stack is full and then push the element to the stack 
  if (s->top==MAX-1){
    printf("stack is full!\nCant push %s",friends);
    return;
  }
  s->top++;
  strcpy (s->arr[s->top],friends);
  printf("pushed the value %s to the stack\n",friends);
}

void check_pop(struct stack *s){
	if (s->top==-1){
		printf("underflow!!\nThe stack is empty\nCannot pop anything!");
		return;
	}
	char popped_friend[20];
	strcpy(popped_friend, s->arr[s->top]);	//this sets the topmost value of the stack 
	s->top--;	//decrease the top most index
	printf("\nPopped %s from the stack!",popped_friend);
}

void display(struct stack *s){
	if (s->top==-1){
		printf("Underflow!\nThe stack is empty!");
		return;
	}

	printf("\nStack elements: ");
	for(int i=s->top; i>=0; i--){
		printf("%s, ",s->arr[i]);
	}
	
}

int main(){
	struct stack s;
	init_stack(&s);
	//pushing on to the stack
	check_Push(&s,"Okwere");
	check_Push(&s,"jamil");
	check_Push(&s,"isma");
	check_Push(&s,"tom");
	check_Push(&s,"blessing");
	check_Push(&s,"femina");
	//popping from the stack
	check_pop(&s);
	check_pop(&s);



	display(&s);

	return 0;
}