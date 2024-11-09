#include<stdio.h>
int main(){
	int array[5];
	int i,min,second_min;
	min=9999;
	for(i=0;i<5;i++){
		printf("Element-%d: ",i);
		scanf("%d",&array[i]);
		if(array[i]<min){
			second_min=min;
			min=array[i];
		}else if(array[i]<second_min && array[i]>min){
			second_min=array[i];
		}
	}
	printf("The second smallest element in array is: %d",second_min);
	return 0;
}
