#include <stdio.h>

int main(){
	int num,factorial=1,i=1;
	printf("Enter number: ");
	scanf("%d",&num);
	if(num>0){
		while(i<=num){
			factorial=factorial*i;
			i++;
		}
		printf("Factorial=%d",factorial);
	}
	else{
		printf("Enter positive number");
	}
	return 0;
}