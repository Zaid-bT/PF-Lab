#include<stdio.h>
int main(){
	int num,factors=0,i,j,next=0,first=0,second=1;
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
		printf("%d is a prime number\n",num);
		printf("Fibonacci series for %d terms: ",num);
		for (j=1;j<=num;j++){
			printf("%d ",first);
			next = first + second;
			first = second;
			second = next;
		}
	}else{
		printf("%d is not a prime number",num);
	}
	return 0;
}
