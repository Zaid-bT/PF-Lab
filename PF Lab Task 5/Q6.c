#include<stdio.h>
int main(){
	int count1;
	int number=0;
	printf("Enter number: ");
	scanf("%d",&number);
	
	if(number & 1){count1++;}
	if(number & 2){count1++ ;}
	if(number & 4){count1++ ;}
	if(number & 8){count1++ ;}
	if(number & 16){count1++ ;}
	if(number & 32){count1++ ;}
	if(number & 64){count1++ ;}
	if(number & 128){count1++ ;}

	printf("Number of 1s in binary representation: %d",count1);
	return 0;
}
