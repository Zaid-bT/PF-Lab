#include<stdio.h>
int main(){
	int i,j,n;
	printf("Enter number: ");
	scanf("%d",&n);
	for(i=1;i<=n+1;i++){
		for(j=n+2-i;j>=1;j--){
			printf(". ");
		}
		for(j=1;j<=i;j++){
			printf("o");
		}
		printf("\n");
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=i+1;j++){
			printf(". ");
		}
		for(j=n+1-i;j>=1;j--){
			printf("o");
		}printf("\n");
	}
	
	return 0;
}
