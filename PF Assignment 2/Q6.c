#include<stdio.h>
int matchsticks(int N){
	if(N%5==0){
		return -1;
	}
	else{
		return N%5;
	}
}
int main(){
	int N,first;
	printf("Enter number of matchsticks: ");
	scanf("%d",&N);
	first=matchsticks(N);
	if(first==-1){
		printf("Impossible to win for A");
	}else{
		printf("To win, A should pick %d matchsticks to win",first);
	}
	return 0;
}
