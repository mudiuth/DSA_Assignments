#include <stdio.h>
# define MAX 5 //defining the size of the stack 

//defining or declaring the struct 
struct stack {
  int top;
  int arr[MAX];
};

void initStack(struct stack *s){  //intitialising the stack 
  s->top=-1;
}

void check_Push(struct stack *s, int val){  //a function that is made to check if the stack is full and then push the element to the stack 
  if (s->top==MAX-1){
    printf("stack is full!\nCant push %d",val);
    return;
  }
  s->top=s->top+1;
  s->arr[s->top]=val;
  printf("pushed the value %d to the stack\n",val);
}

void display(struct stack *s){  //function to display the stack and the pushed elements 
  if(s->top==-1){
    printf("the stack is empty");
    return;
  }

  printf("\nstack elements: ");
  for(int i=s->top; i>=0; i--){
    printf("%d, ", s->arr[i]);
  }
  printf("\n");
}

int main(){

struct stack s;
initStack(&s);
check_Push(&s, 20);
check_Push(&s, 30);
check_Push(&s,40);

display(&s);

  return 0;
}