#include<stdio.h>
int main(){
	float percentage;
	char grade;
	printf("Enter percentage: ");
	scanf("%f",&percentage);
	
	grade=(percentage >= 90) ? 'A' : 
	(percentage >= 80) ? 'B':
	(percentage >= 70) ? 'C':
	(percentage >= 60) ? 'D': 'F';
	
	printf("Your grade is: %c",grade);
	return 0;
}