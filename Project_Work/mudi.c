#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//transaction record
typedef struct Transaction {
	char type;
	float amount;
	time_t timestamp;
	struct Transaction *next;
}Transaction;

//acct infomation 
typedef struct Farmer{
	int id;
	char name[50];
	float acctBal;
	struct Farmer *next;
	Transaction *transaction; //list of all transactions 
}Farmer;

typedef struct stackNode {
	Transaction *transaction;
	struct stackNode*next;
}stackNode;

typedef struct {
	stackNode*top;
	int size;
}stack;



#define MAX_FARMERS 100
Farmer *farmer[MAX_FARMERS] = {NULL};

unsigned int hash(int id){
	return id % MAX_FARMERS;
}

//creating a new farmer acct 
Farmer *newFarmer(int id, const *char name, float acctBal){
	unsigned int index = hash(id);
	Farmer *newFarmer= (Farmer *)malloc(sizeof(Farmer));

	newFarmer->id = id;
	newFarmer->acctBal = acctBal;
	strcpy(newFarmer->name,name);
	newFarmer->transaction = NULL;
	farmer[index]=newFarmer;
	return newFarmer;
}

Farmer *searchFarmer (int id){
	unsigned int index = hash(id);
	Farmer *temp = farmer[index];

	while (temp != NULL){
		if(temp->id==id)
			return temp;
		temp = temp->next;
	}
	return NULL;
}


//add transaction to afarmer's history
void addTransaction(Farmer *farmer, char type, float amount){

	Transaction *newTrans = (Transaction *)malloc(sizeof(Transaction));
	newTrans->amount = amount;
	strcpy(newTrans->type, type);
	newTrans->timestamp =time(NULL);
	newTrans->next=NULL; //initialising 

	newTrans->next = farmer->transaction;

	//update balance after addTransaction
	if(type == 'D'){
		farmer->acctBal += amount;
		//return;
	}else if(type == 'W'){
		farmer->acctBal -= amount;
		return;
	}
}

void deposit (Farmer *farmer, float amount){
	if (amount<500){
		printf("Invalid amount to deposit\nMin is 500");
		return;
	}
	addTransaction(farmer, D, amount);
	printf("Deposited %.2f. New balance is %.2f",amount,farmer->acctBal);
}

void withdraw (Farmer *farmer, float amount){
	if (amount <= 0){
		printf("please enter the valid amount to withdraw! ");
		return;
	}
	if(amount > farmer->acctBal){
		pritf("insufficient funds! please check you account and try again");
		return;
	}
	addTransaction(farmer, W, amount)
	printf("withdrew %.2f, new balance is %.2f",amount. farmer->acctBal);
}


void pushT(stack *s, Transaction *t){
	stackNode *newNode=(stackNode *)malloc(sizeof(stackNode));
	newNode->transaction = t;
	newNode->next = s->top;
	s->top = newNode;
	s->size++;
}

Transaction *pop(stack *s){
	if (s->top == NULL)
		return NULL;
	stackNode *temp = s->top;
	Transaction *t = temp->transaction;
	s->top = temp->next;
	free(temp);
	s->size--;
	return t;
}


//get last transaction using the stack 
void getTrans(Farmer *f, int n){
	if (n<=0) 
		return;
	stack s ={NULL,0};

	Transaction *current = farmer->transaction;

	while (current != NULL){
		push(&s, current);
		current = current->next;
	}
	printf("last %d transactions:\n", n);
	printf("Type \tAmount \tDate\n");

	//present n transactions from stack

	for (int i=0; i<n && s->size>0; i++){
		Transaction *t = pop(&s);
		char *type =(trans->type == 'D') ? "Deposit" : "Withdraw";
		printf("%s\t.2f\t%s",type, t->amount, ctime(&t->timestamp));
	}
	//freeing any remaining stack nodes
	while (stack.size >0){
		pop(&s);
	}
}


Farmer *createFarmer(int id){
	Farmer *farmer = (Farmer *)malloc(sizeof(Farmer));
	addFarmer ->id = id;
	addFarmer -> acctBal = 0.00;
	addFarmer -> transaction = NULL;

	newFarmer(addFarmer);
	return addFarmer;
}

void MainMenu(){

	const char *options[]= {"Deposit Money", "Withdraw Money", "Check Balance"};
	int _size = sizeof(options)/sizeof(options[0]);
	for(int i=0; i<_size; i++){
		printf("\n%d. %s", i + 1, options[i]);
	}

