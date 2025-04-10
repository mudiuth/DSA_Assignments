/* am to mamke a data structure implementation sacco that will have to provede financial services to the farmers
these services will include;
withdrawals: a farmer withdraws the amount that he has so the function shud fst chdck thebalance and also verify the acct 
depositing: the farmer shud be able to top up the money she or he is having on their acct and this is the depositing process.. all that is required is to check the availability of the acct. all deposit shud store the time stamps 
check balance: this function shud be able to return the actual balance the farmer has withou any error

below is the data needed 
AcctName
AcctBalance
AcctNo_
AcctPin
DepositedAmount

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define FILE_NAME "farmers.dat"
#define MAX_TRANSACTIONS 100

typedef struct Transaction {
    char type;
    float amount;
    time_t timestamp;
} Transaction;

typedef struct Farmer {
    int id;
    char name[50];
    float acctBal;
    char pin[5];
    int transactionCount;
    Transaction transactions[MAX_TRANSACTIONS];
} Farmer;

/*typedef struct stackNode {
    Transaction *transaction;
    struct stackNode *next;
} stackNode;*/

typedef struct {
    stackNode *top;
    int size;
} stack;

#include <termios.h>
#include <unistd.h>
void getHiddenPin(char *pin, int length){
    struct termios oldt, newt;
    int i=0;
    char ch;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    while (i< length){
        ch = getchar();
        if(ch >= '0' && ch<= '9'){
            pin[i++] = ch;
            printf("*");
        }else if((ch==127 || ch == 8) && i > 0){
            //if(i > 0){
                i--;
                printf("\b \b"); 
                //return;
           // }
        }
    }
    pin[i] = '\0';

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    printf("\n");
}


#define MAX_FARMERS 100
Farmer *farmer[MAX_FARMERS] = {NULL};

unsigned int hash(int id) {
    return id % MAX_FARMERS;
}

int farmercount = 0;
Farmer *newFarmer(const char *name) {
    Farmer *newFarmer = (Farmer *)malloc(sizeof(Farmer));
    farmercount++;

    newFarmer->id = farmercount;
    newFarmer->acctBal = 0.00;
    strcpy(newFarmer->name, name);
    newFarmer->transactionCount = 0;

    unsigned int index = hash(newFarmer->id);
    farmer[index] = newFarmer;

    return newFarmer;
}

Farmer *searchFarmer(int id) {
    unsigned int index = hash(id);
    Farmer *temp = farmer[index];
    return temp; // Since no linked list, return the farmer at the index or NULL

    if(temp != NULL && temp->id == id){
        return temp;
    }
    return NULL;
}

void addTransaction(Farmer *farmer, char type, float amount) {
    if (farmer->transactionCount < MAX_TRANSACTIONS) {
        farmer->transactions[farmer->transactionCount].amount = amount;
        farmer->transactions[farmer->transactionCount].type = type;
        farmer->transactions[farmer->transactionCount].timestamp = time(NULL);
        farmer->transactionCount++;

        if (type == 'D') {
            farmer->acctBal += amount;
        } else if (type == 'W') {
            farmer->acctBal -= amount;
        }
    }
}

void deposit(Farmer *farmer, float amount) {
    if (amount < 500) {
        printf("Invalid amount to deposit\nMin is 500");
        return;
    }
    addTransaction(farmer, 'D', amount);
    printf("Deposited %.2f. New balance is %.2f\n", amount, farmer->acctBal);
}

void withdraw(Farmer *farmer, float amount) {
    if (amount <= 0) {
        printf("please enter the valid amount to withdraw! ");
        return;
    }
    if (amount > farmer->acctBal) {
        printf("insufficient funds! please check you account and try again");
        return;
    }
    addTransaction(farmer, 'W', amount);
    printf("withdrew %.2f, new balance is %.2f\n", amount, farmer->acctBal);
}

void push(stack *s, Transaction *t) {
    stackNode *newNode = (stackNode *)malloc(sizeof(stackNode));
    newNode->transaction = t;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

Transaction *pop(stack *s) {
    if (s->top == NULL)
        return NULL;
    stackNode *temp = s->top;
    Transaction *t = temp->transaction;
    s->top = temp->next;
    free(temp);
    s->size--;
    return t;
}

void getTrans(Farmer *f, int n) {
    if (n <= 0 || f->transactionCount == 0)
        return;
    stack s = {NULL, 0};

    for (int i = 0; i < f->transactionCount; i++) {
        push(&s, &f->transactions[i]);
    }

    printf("last %d transactions:\n", n);
    printf("Type \tAmount \tDate\n");

    for (int i = 0; i < n && s.size > 0; i++) {
        Transaction *t = pop(&s);
        char *type = (t->type == 'D') ? "Deposit" : "Withdraw";
        printf("%s\t%.2f\t%s", type, t->amount, ctime(&t->timestamp));
    }

    while (s.size > 0) {
        pop(&s);
    }
}

void saveFarmerToFile(Farmer *f) {
    FILE *file = fopen(FILE_NAME, "ab");  // Added 'FILE' type
    if (file == NULL) {
        printf("Error accessing the file to write and read data.\n");
        return;
    }
    fwrite(f, sizeof(Farmer), 1, file);
    fclose(file);
}

int loadFarmersFromFile() {
    FILE *file = fopen(FILE_NAME, "rb");  // Added 'FILE' type
    if (file == NULL) {
        return 0;
    }

    Farmer temp;
    while (fread(&temp, sizeof(Farmer), 1, file)) {
        Farmer *f = (Farmer *)malloc(sizeof(Farmer));
        *f = temp;
        unsigned int index = hash(f->id);
        farmer[index] = f;
        if (f->id > farmercount) {
            farmercount = f->id;
        }
    }
    fclose(file);
    return 1;
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
            scanf(" %[^\n]", name);
            printf("Select a 4 digit pin for your account: ");
            Farmer *f = newFarmer(name);
            getHiddenPin(f->pin, 4);
            printf("pin set successfully");

            //f = newFarmer(name);
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
            saveFarmerToFile(f);
            printf("Account activated. Your current balance is: %.2f UGX\n", f->acctBal);

        } else if (choice == 2) {
            int id;
            printf("Enter your Farmer ID: ");
            scanf("%d", &id);
            Farmer *f = searchFarmer(id);
            if (f == NULL) {
                printf("No account found with that ID.\n");
                continue; // Changed from exit(0) to continue
            } else {
                printf("Welcome back, %s!\n", f->name);
                printf("Please enter your Pin:\n");
                

                char enteredPin[5];
                printf("Enter Your PIN: ");
                getHiddenPin(enteredPin, 4);

                if (strcmp(enteredPin, f->pin) !=0){
                    printf("Incorrect PIN. Access denied \n");
                    continue;
                }
                printf("What wud u like to do today?\n");
                printf("1. Deposit\n2. Withdraw\n3. View Last Transactions\n4. Check balance\n5. Logout\n");
                scanf("%d", &choice);

                if (choice == 1) {
                    float depositAmt;
                    printf("please enter the amount to deposit:\n");
                    scanf("%f", &depositAmt);

                    while (depositAmt < 1000) {
                        printf("deposit should be atleast 1000 UGX:");
                        scanf("%f", &depositAmt);
                    }

                    addTransaction(f, 'D', depositAmt);
                    printf("Transaction successfull. New balance is %.2f UGX\n", f->acctBal);
                } else if (choice == 2) {
                    float withdrawAmt;
                    printf("please enter amount to withdraw!\n");
                    scanf("%f", &withdrawAmt);
                    while (withdrawAmt < 1000) {
                        printf("Please enter a reasonable amount greater than 1000 UGX!");
                        scanf("%f", &withdrawAmt);
                    }
                    withdraw(f, withdrawAmt); // Fixed call to withdraw function
                } else if (choice == 3) {
                    int n;
                    printf("How many transactions to view? ");
                    scanf("%d", &n);
                    getTrans(f, n);
                }else if (choice == 4){
                    printf("Your acct balance is %.2f",f->acctBal);
                    continue;
                }
            }
        } else if (choice == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    loadFarmersFromFile();
    mainMenu();
    return 0;
}