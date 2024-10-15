#include<stdio.h>
int main(){
	int arr[]={2,4,6,8,10};
	int i,num;
	printf("Enter number to be searched: ");
	scanf("%d",&num);
	for(i=0;i<5;i++){
		if(arr[i]==num){
			printf("Number found at Array Index %d",i);
			return 0;
		}
	}
	printf("Number not found in Array");
	return 0;
}
