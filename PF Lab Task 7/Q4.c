#include<stdio.h>
int main(){
	int i,total=0;
	int numArray[15];
	for(i=0;i<15;i++){
		printf("Enter number: ");
		scanf("%d",&numArray[i]);
		total+=numArray[i];
	}
	printf("Total sum of array elements= %d",total);

	return 0;
}
