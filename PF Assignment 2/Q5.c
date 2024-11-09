#include<stdio.h>
int main(){
	int index,i,j,max;
	int values[index];
	printf("Enter number of values: ");
	scanf("%d",&index);
	for(i=0;i<index;i++){
		printf("Enter value %d: ",i+1);
		scanf("%d",&values[i]);
	}
	printf("\nHORIZONTAL HISTROGRAM\n");
	for(i=0;i<index;i++){
		printf("%d| ",values[i]);
		for(j=0;j<values[i];j++){
			printf("*");
		}printf("\n");
	}	
	max=values[0];
	for(i=0;i<index;i++){
		if(values[i]>max){
			max=values[i];
		}
	}
	printf("\nVERTICAL HISTROGRAM\n");
	for(i=max;i>0;i--){
		for(j=0;j<index;j++){
			if(values[j]>=i){
				printf("* ");
			}else{
				printf("  ");
			}
		}printf("\n");
	}
	for(i=0;i<index;i++){
		printf("%d ",values[i]);
	}printf("\n");
	
	return 0;
}
