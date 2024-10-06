# include<stdio.h>

int main (){
	float length;
	float width;
	float area;
	float perimeter;
	printf("enter length: ");
	scanf("%f", &length);
	printf("enter width: ");
	scanf("%f", &width);
	area = length*width;
	perimeter = 2*(length+width);
	printf("Area of Rectangle: %f\n",area);
	printf("Perimeter of Rectangle: %f", perimeter);
	return 0;
}
