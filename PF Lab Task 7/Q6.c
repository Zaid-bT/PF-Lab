#include<stdio.h>
int main(){
	int array[30];
	int i,min,max;
	for(i=0;i<30;i++){
		printf("Enter number: ");
		scanf("%d",&array[i]);
	}
min=array[0];
max=array[0];
	for(i=0;i<30;i++){
		if(array[i]<min){
			min=array[i];
		}
		if(array[i]>max){
			max=array[i];
		}
	}
	printf("Maximum: %d\n",max);
	printf("Minimum: %d",min);
	return 0;
}
