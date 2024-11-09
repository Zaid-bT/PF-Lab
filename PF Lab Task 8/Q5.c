#include<stdio.h>
int main(){
	int i,j,temp,score[3][3];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Enter Round %d score for Team %d: ",j+1,i+1);
			scanf("%d",&score[i][j]);
		}printf("\n");
	}
	printf("Columns in ascending order: \n");
	for(j=0;j<3;j++){
		for(i=0;i<2;i++){
			if(score[i][j]>score[i+1][j]){
				temp=score[i][j];
				score[i][j]=score[i+1][j];
				score[i+1][j]=temp;
			}
		}
	}
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%d ",score[i][j]);
		}printf("\n");
	}
	return 0;
}
