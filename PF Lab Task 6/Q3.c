#include<stdio.h>

int main(){
	int num;
	printf("Enter a positive number: ");
	scanf("%d",&num);
	do {
		printf("Wrong, enter a positive number: ");
		scanf("%d",&num);
	}while(num<=0);
	printf("Valid number entered: %d",num);
	
	return 0;
}
