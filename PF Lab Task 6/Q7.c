#include<stdio.h>
int main(){
	int num,saveNum;
	int digit,total;
	printf("Enter number: ");
	scanf("%d",&num);
	saveNum=num;
	while(num!=0){
		digit=num%10;
		total+=digit*digit*digit;
		num=num/10;
	}
	if(total==saveNum){
		printf("Your number is an Armstrong number");
	}
	else{
		printf("Your number is not an Armstrong number");
	}
	return 0;
}
