#include<stdio.h>
int main(){
	int i,j,m,n;
	printf("Enter number of rows: ");
	scanf("%d",&m);
	printf("Enter number of columns: ");
	scanf("%d",&n);
	int matrix1[m][n],matrix2[m][n],sum[m][n];
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("Enter value for matrix 1: ");
			scanf("%d",&matrix1[i][j]);
		}
	}printf("\n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			printf("Enter value for matrix 2: ");
			scanf("%d",&matrix2[i][j]);
		}
	}printf("\n Addition matrix of the 2 matrices: \n");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			sum[i][j]=matrix1[i][j]+matrix2[i][j];
			printf("%d ",sum[i][j]);
		}printf("\n");
	}
	return 0;
}
