#include<stdio.h>
int main(){
	float a1,a2,a3;
	printf("Enter the three angles: ");
	scanf("%f,%f,%f",&a1,&a2,&a3);
	if (a1<=0 || a2<=0 || a3<=0){
		printf("Invalid angles");
	}
	else{
		if (a1+a2+a3 == 180){
			printf("valid triangle");
		}
		else{
			printf("not a triangle");
		}
	}
	return 0;
}