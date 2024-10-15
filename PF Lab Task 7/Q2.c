#include<stdio.h>
int main(){
	int arr[10];
	int i;
	for(i=0;i<10;i++){
		printf("Enter number: ");
		scanf("%d",&arr[i]);
	}
	printf("Before: {");
	for(i=0;i<10;i++){
		printf("%d",arr[i]);
		if(i<9){
			printf(",");
		}
	}printf("}\n");
	
	printf("After: {");
	for(i=0;i<10;i++){
		arr[i]=arr[i+1];
		printf("%d",arr[i]);
		if(i<9){
			printf(",");
		}
	}printf("}\n");
	return 0;
}
