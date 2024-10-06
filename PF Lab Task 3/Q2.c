# include<stdio.h>

int main (){
	int Num1;
	int Num2;
	int sum;
	int product;
	printf("enter first number: ");
	scanf("%d", &Num1);
	printf("enter second number: ");
	scanf("%d", &Num2);
	sum = Num1+Num2;
	product = Num1*Num2;
	printf("Sum = %d\n",sum);
	printf("Product = %d",product);
	
	return 0;
}

