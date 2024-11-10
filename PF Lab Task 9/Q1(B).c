#include<stdio.h>
int main(){
	int i,j,k,n;
	printf("Enter number: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			printf("%d",j);
		}
		for(k=i-1;k>=1;k--){
			if(k==0){
				break;
			}else{
			printf("%d",k);
		}
		}
		printf("\n");
	}
	
	return 0;
}
