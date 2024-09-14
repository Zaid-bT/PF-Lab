#include<stdio.h>
int main(){
	int cost;
	float sale_price,money_saved;
	printf("Enter cost of items: ");
	scanf("%d",&cost);
	if (cost<1500){
		printf("Orignal price: Rs.%d\n",cost);
		sale_price = cost-(cost*0.07);
		printf("Price after discount: Rs.%f\n",sale_price);
		money_saved = cost-sale_price;
		printf("Money saved: Rs.%f\n",money_saved);
	}
	else if (cost>=1500 && cost<3000){
		printf("Orignal price: Rs.%d\n",cost);
		sale_price = cost-(cost*0.12);
		printf("Price after discount: Rs.%f\n",sale_price);
		money_saved = cost-sale_price;
		printf("Money saved: Rs.%f\n",money_saved);
	}
	else if (cost>=3000 && cost<5000){
		printf("Orignal price: Rs.%d\n",cost);
		sale_price = cost-(cost*0.22);
		printf("Price after discount: Rs.%f\n",sale_price);
		money_saved = cost-sale_price;
		printf("Money saved: Rs.%f\n",money_saved);
	}
	else if (cost>5000){
		printf("Orignal price: Rs.%d\n",cost);
		sale_price = cost-(cost*0.30);
		printf("Price after discount: Rs.%f\n",sale_price);
		money_saved = cost-sale_price;
		printf("Money saved: Rs.%f\n",money_saved);
	}
	return 0;
}
