#include<stdio.h>
int main(){
	int i,j,totalScore,totalActivity;
	int matrix[3][3];
	for(i=0;i<3;i++){
		printf("Person %d: \n",i+1);
		for(j=0;j<3;j++){
			printf("Score %d:",j+1);
			scanf(" %d",&matrix[i][j]);
		}printf("\n");
	}
	for(i=0;i<3;i++){
		totalScore=0;
		for(j=0;j<3;j++){
			totalScore+=matrix[i][j];
		}
		printf("Total score of person %d: %d \n",i+1,totalScore);
	}
	printf("\n");
	for(j=0;j<3;j++){
		totalActivity=0;
		for(i=0;i<3;i++){
			totalActivity+=matrix[i][j];
		}
		printf("Total score of activity %d: %d \n",j+1,totalActivity);
	}
	return 0;
}
