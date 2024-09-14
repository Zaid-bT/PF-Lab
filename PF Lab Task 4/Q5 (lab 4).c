#include<stdio.h>
int main(){
	int time;
	printf("Enter time (24hr format): ");
	scanf("%d",&time);
	if (time>=6 && time<12){
		printf("Good Morning");
	}
	else if (time>=12 && time<18){
		printf("Good Afternoon");
	} 
	else if (time>=18 && time<24){
		printf("Good Evening");
	}
	else if (time>=0 && time<6){
		printf("Good Night");
	}
	else {
		printf("Invalid time entered");
	}
	return 0;
}
