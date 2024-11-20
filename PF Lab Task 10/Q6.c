#include<stdio.h>
#include<string.h>

void Reverse(char str[],int Num_of_Letters){
	int j=Num_of_Letters-1;
	if(j<0){
		return;
	}
	printf("%c",str[j]);
	
	Reverse(str,Num_of_Letters-1);
}

int main(){
	int i;
	char string[50];
	printf("Enter word: ");
	fgets(string, 50, stdin);
	i=strlen(string);
	
	Reverse(string,i);
	return 0;
}
