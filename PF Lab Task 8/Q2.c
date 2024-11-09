#include<stdio.h>
int main(){
	int matrix[4][4];
	int i,j;
	for(i=0;i<4;i++){
		printf("Student %d: \n",i+1);
		for(j=0;j<4;j++){
			printf("Subject %d Marks:",j+1);
			scanf(" %d",&matrix[i][j]);
		}printf("\n");
	}
	printf("BEFORE:\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
		printf("%d ",matrix[i][j]);	
		}printf("\n");
	}
	printf("\nAFTER:\n");
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(matrix[i][j]<0){
				matrix[i][j]=0;
			}
		printf("%d ",matrix[i][j]);	
		}printf("\n");
	}
	return 0;
}
