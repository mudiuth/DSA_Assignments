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

void MainMenu(){

	const char *options[]= {"Deposit Money", "Withdraw Money", "Check Balance"};
	int _size = sizeof(options)/sizeof(options[0]);
	for(int i=0; i<_size; i++){
		printf("\n%d. %s", i + 1, options[i]);
	}
}

int main(){

printf("welcome to THE MINER SAVINGS SACCO \nBig from nothing");
printf("\nPlease select your option;");

MainMenu();




	return 0;
}
