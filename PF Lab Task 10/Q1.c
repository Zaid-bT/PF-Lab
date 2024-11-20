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
	char sentence[50];
	printf("Enter a sentence: ");
	fgets(sentence, 50, stdin);
	
	Reverse(sentence,11);
	return 0;
}
