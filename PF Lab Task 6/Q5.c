#include<stdio.h>
int main(){
	int num,factors=0,i;
	printf("Enter number: ");
	scanf("%d",&num);
	if (num<=1){
		printf("0 and 1 are not prime number");
		return 0;
	}
	else{
		for (i = 2;i <= num;i++){
			if(num%i==0){
				factors++;
			}
		}
	}
	if(factors==1){
		printf("%d is a prime number",num);
	}else{
		printf("%d is not a prime number",num);
	}
	return 0;
}
