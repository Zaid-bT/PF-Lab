#include <stdio.h>
int main(){
	float cost;
	char member,discount;
	printf("Enter total cost: ");
	scanf("%f",&cost);
	printf("Are you a member?(Y or N): ");
	scanf(" %c",&member);
	
	discount=(cost>100 && member=='Y') ? 'Y' : 'N';
	(discount=='Y') ? printf("You get discount\nFinal cost:%.2f",cost-cost*0.1) : 
	printf("No discount for you\nFinal cost:%.2f",cost);  
	
	return 0;
}
