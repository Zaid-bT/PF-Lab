#include<stdio.h>
int main(){
	int num;
	printf("Enter number: ");
	scanf("%d",&num);
	if (num & 1){
		printf("Number is Odd");
	}
	else {
		printf("Number is Even");
	}
	return 0;
}
