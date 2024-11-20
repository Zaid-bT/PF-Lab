#include<stdio.h>

int digitSum(int num){
	if(num==0){
		return 0;
	}
	return (num%10)+digitSum(num/10);
}

int main(){
	int n,total;
	printf("Enter number: ");
	scanf("%d",&n);
	total=digitSum(n);
	printf("Sum of digits: %d",total);
	return 0;
}
