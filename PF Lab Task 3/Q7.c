# include<stdio.h>

int main (){
	printf("coordinates: \n(5,4) and (3,2)\n");
	int x1=5, x2=3, y1=4, y2=2;
	float slope;
	printf("slope = (y2-y1)/(x2-x1)\n");
	slope = (y2-y1)/(x2-x1);
	printf("slope of coordinates (5,4) and (3,2) = %.3f", slope);
	
	return 0;
}
