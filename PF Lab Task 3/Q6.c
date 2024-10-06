# include<stdio.h>

int main (){
	float principle;
	float interest_rate;
	float time_period;
	float interest;
	printf("*PRINCIPLE MUST BE BETWEEN RS.100-1,000,000*\n");
	printf("Enter Principle amount: ");
	scanf("%f", &principle);
	printf("*RATE OF INTEREST MUST BE BETWEEN 5 to 10 percent*\n");
	printf("Enter Rate of Interest: ");
	scanf("%f", &interest_rate);
	printf("*TIME PERIOD MUST BE BETWEEN 1-10 YEARS*\n");
	printf("Enter Time Period : ");
	scanf("%f", &time_period);
	interest = ((principle*time_period*interest_rate)/100);
	printf("Simple Interest = Rs.%f", interest);
	
	return 0;
}
