#include <stdio.h>
int main(){

int subjects [3][4]={
	{50,40,60,80},//mtc
	{40,80,70,60},//chem
	{66,45,67,88}//phy
};

//printf("math mid term results: %d",subjects[0][0]);
float AverageMtc= (float)(subjects[0][0]+subjects[0][1]+subjects[0][2]+subjects[0][3])/4;
float AverageChem= (float)(subjects[1][0]+subjects[1][1]+subjects[1][2]+subjects[1][3])/4;
float AveragePhy= (float)(subjects[2][0]+subjects[2][1]+subjects[2][2]+subjects[2][3])/4;

printf("the average of math = %.2f",AverageMtc);
 printf("\nthe average of chemistry = %.2f",AverageChem);
 printf("\nthe average of physics = %.2f",AveragePhy);


return 0;

}