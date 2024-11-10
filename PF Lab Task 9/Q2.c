#include<stdio.h>
int main(){
	int b,n,w,cost;
	printf("Enter number of bolts: ");
	scanf("%d",&b);
	printf("Enter number of nuts: ");
	scanf("%d",&n);
	printf("Enter number of washers: ");
	scanf("%d",&w);
	cost=b*5 + n*8 + w*1;
	if(n<b || 2*w<b){
		if(n<b){
			printf("Check order: Too few nuts\n");
		}if(2*w<b){
			printf("Check order: Too few washers\n");
		}
		printf("Total Cost: %d cents",cost);
	}else{
		printf("Order is OK \nTotal Cost: %d cents",cost);
	}
	return 0;
}
