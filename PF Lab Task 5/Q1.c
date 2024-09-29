#include<stdio.h>
int main(){
	int age;
	char citizen;
	printf("Enter your age: ");
	scanf("%d",&age);
	if (age >= 18){
		printf("Are you a citizen?(Y or N): ");
		scanf(" %c",&citizen);
		if (citizen ="Y"){
			printf("Eligible for voting");
		}
		else{
			printf("Not eligible for voting");
		}
	}
	else{
		printf("Not eligible for voting");
	}	
	return 0;
}