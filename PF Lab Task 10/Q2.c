#include<stdio.h>
	
void percentage(float num,int i){
	if(i>100){
		return;
	}
	float percent;
	percent=num*i/100;
	printf("%d percent= %.2f\n",i,percent);
	percentage(num,i+1);
}
                       
int main(){
	percentage(200,1);
	return 0;
}
