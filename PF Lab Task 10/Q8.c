#include<stdio.h>

void PrintArray(int arr[],int size){
	 if (size == 0) {
        return;
    }
    printf("%d ", arr[0]);
    PrintArray(arr + 1, size - 1);
}

 
int main(){
	int i,j;
	printf("Enter number of array indexes: ");
	scanf("%d",&i);
	int numbers[i];
	for(j=0;j<i;j++){
		printf("Enter number %d: ",j+1);
		scanf("%d",&numbers[j]);
	}
	printf("Array elements: ");
	PrintArray(numbers,i);
	return 0;
}
