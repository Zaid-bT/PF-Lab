#include<stdio.h>
int main(){
	int unit;
	float bill,final_bill;
	printf("Enter number of units: ");
	scanf("%d", &unit);
	if (unit<=30){
		bill = unit*0.6;
		printf("Bill = Rs.%f\n",bill);
	}
	else if (unit>30 && unit<=110){
		bill = (30*0.6)+((unit-30)*0.85);
		printf("Bill = Rs.%f\n",bill);
	}
	else if (unit>110 && unit<=210){
		bill = (30*0.6)+(80*0.85)+((unit-110)*1.3);
		printf("Bill = Rs.%f\n",bill);
	}
	else if (unit>210){
		bill = (30*0.6)+(80*0.85)+(100*1.3)+((unit-210)*1.6);
		printf("Bill = Rs.%f\n",bill);
	}
	final_bill = bill + (bill*0.15);
	printf("Final bill(with 15%% surcharge) = Rs.%f",final_bill);
	return 0;
}
