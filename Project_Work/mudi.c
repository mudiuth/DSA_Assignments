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
int farmercount = 0;
Farmer *newFarmer(const char *name){
	Farmer *newFarmer= (Farmer *)malloc(sizeof(Farmer));
	farmercount++;

	newFarmer->id = farmercount;
	newFarmer->acctBal = 0.00;
	strcpy(newFarmer->name,name);
	newFarmer->transaction = NULL;
	newFarmer->next = NULL;

	unsigned int index = hash(newFarmer->id);
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
	newTrans->type = type;
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
	addTransaction(farmer, 'D', amount);
	printf("Deposited %.2f. New balance is %.2f",amount,farmer->acctBal);
}

void withdraw (Farmer *farmer, float amount){
	if (amount <= 0){
		printf("please enter the valid amount to withdraw! ");
		return;
	}
	if(amount > farmer->acctBal){
		printf("insufficient funds! please check you account and try again");
		return;
	}
	addTransaction(farmer, 'W', amount);
	printf("withdrew %.2f, new balance is %.2f",amount, farmer->acctBal);
}


void push(stack *s, Transaction *t){
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

	Transaction *current = f->transaction;

	while (current != NULL){
		push(&s, current);
		current = current->next;
	}
	printf("last %d transactions:\n", n);
	printf("Type \tAmount \tDate\n");

	//present n transactions from stack

	for (int i=0; i<n && s.size>0; i++){
		Transaction *t = pop(&s);
		char *type =(t->type == 'D') ? "Deposit" : "Withdraw";
		printf("%s\t%.2f\t%s",type, t->amount, ctime(&t->timestamp));
	}
	//freeing any remaining stack nodes
	while (s.size >0){
		pop(&s);
	}
}


void mainMenu() {
    int choice;
    while (1) {
        printf("\nWelcome to the Farmer Account System\n");
        printf("1. Create New Account\n");
        printf("2. Access Existing Account\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char name[50];
            printf("Enter your name: ");
             scanf(" %[^\n]", name); // Accepts full name with spaces

            Farmer *f = newFarmer(name); // Create new farmer
            printf("Account created successfully!\n");
            printf("Your Farmer ID is: %05d\n", f->id);
            printf("Name: %s\n", f->name);

            float depositAmt;
            printf("Please deposit at least 1000 UGX to activate your account: ");
            scanf("%f", &depositAmt);

            while (depositAmt < 1000) {
                printf("Deposit must be at least 1000 UGX: ");
                scanf("%f", &depositAmt);
            }

            addTransaction(f, 'D', depositAmt);
            printf("Account activated. Your current balance is: %.2f UGX\n", f->acctBal);

        } else if (choice == 2) {
            int id;
            printf("Enter your Farmer ID: ");
            scanf("%d", &id);
            Farmer *f = searchFarmer(id);
            if (f == NULL) {
                printf("No account found with that ID.\n");
                exit(0);
            } else {
                printf("Welcome back, %s!\n", f->name);
                printf("What wud u like to do today?\n");
                printf("1. Deposit\n2. Withdraw\n3. View Last Transactions\n4. Logout\n");
                scanf("%d",&choice);

                if (choice == 1){
                	float depositAmt;
                	printf("please enter the amount to deposit:\n");
                	scanf("%f", &depositAmt);

                	while (depositAmt < 1000){
                		printf("deposit should be atleast 1000 UGX:");
                		scanf("%f", &depositAmt);
                	}

                	addTransaction(f, 'D', depositAmt);
                	printf("Transaction successfull. New balance is %.2f UGX\n",f->acctBal);
                }else if (choice == 2){
                	float withdrawAmt;
                	printf("please enter amount to withdraw!\n");
                	scanf("%f", &withdrawAmt);
                	while (withdrawAmt < 1000){
                		printf("Please enter a reasonable amount greater than 1000 UGX!");
                		scanf("%f", &withdrawAmt);
                	}
                	addTransaction(f, 'W', withdrawAmt);
                	printf("Transaction successfull! your acct balance is %.2f UGX\n",f->acctBal);
                }

                // more changes coming in here... we need to call these functions 
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

int main(){
	mainMenu();
	return 0;
}