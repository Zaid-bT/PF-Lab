#include<stdio.h>
int main(){
	int arr[12];
	int sumArr[6];
	int i;
	for(i=0;i<12;i++){
		printf("Enter number: ");
		scanf("%d",&arr[i]);
	}
	for(i=0;i<6;i++){
		sumArr[i]=arr[i*2]+arr[i*2+1];
	}
	printf("Input Array: {");
	for(i=0;i<12;i++){
		printf("%d",arr[i]);
		if(i<11){
			printf(",");
		}
	}printf("}\n");
	printf("Pair Sum Array: {");
	for(i=0;i<6;i++){
		printf("%d",sumArr[i]);
		if(i<5){
			printf(",");
		}
	}printf("}\n");
	return 0;
}
