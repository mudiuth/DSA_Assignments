#include <stdio.h>
#define MAX 5

struct stack {
	int top;
	int arr[MAX];//array to store the elements 
};

void init_stack (struct stack *s){
	s->top=-1;
}

void check_Push(struct stack *s, int val){  //a function that is made to check if the stack is full and then push the element to the stack 
  if (s->top==MAX-1){
    printf("stack is full!\nCant push %d",val);
    return;
  }
  s->top++;
  s->arr[s->top]=val;
  printf("pushed the value %d to the stack\n",val);
}

void check_pop(struct stack *s){
	if (s->top==-1){
		printf("underflow!!\nThe stack is empty\nCannot pop anything!");
		return;
	}

	int popped_value = s->arr[s->top];	//this sets the topmost value of the stack 
	s->top--;	//decrease the top most index
	printf("\nPopped %d from the stack!",popped_value);
}

void display(struct stack *s){
	if (s->top==-1){
		printf("Underflow!\nThe stack is empty!");
		return;
	}

	printf("\nStack elements: ");
	for(int i=s->top; i>=0; i--){
		printf("%d, ",s->arr[i]);
	}
	
}

int main(){
	struct stack s;
	init_stack(&s);
	//pushing on to the stack
	check_Push(&s,20);
	check_Push(&s,30);
	check_Push(&s,40);
	check_Push(&s,50);
	check_Push(&s,60);
	check_Push(&s,90);
	//popping from the stack
	check_pop(&s);
	check_pop(&s);



	display(&s);

	return 0;
}