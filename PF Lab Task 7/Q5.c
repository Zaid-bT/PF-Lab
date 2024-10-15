#include<stdio.h>
int main(){
	int array[20];
	int i,j;
	for(i=0;i<20;i++){
		printf("Enter number: ");
		scanf("%d",&array[i]);
	}
	for(j=19;j>-1;j--){
		printf("%d ",array[j]);
	}

	return 0;
}
