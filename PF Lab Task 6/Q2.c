#include<stdio.h>

int main(){
	int num,i=2;
	printf("Enter number: ");
	scanf("%d",&num);
	if(num>=1){
		while(i<=num){
			printf("%d\n",i);
			i+=2;
		}
	}
	return 0;
}
