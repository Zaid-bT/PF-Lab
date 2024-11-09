#include<stdio.h>
#include<string.h>
void lessWords(char *input, char *output){
	int i,j=0;
	for(i=0;i<strlen(input);i++){
		if(input[i]!=input[i+1]){
			output[j]=input[i];
			j++;
		}
	}
	printf("%s",output);
}
int main(){
	printf("Word should be less that 20 characters! \n\n");
	char a[20];
	char b[strlen(a)];
	while(1){
		printf("\nEnter word here(enter xyz to exit): ");
		scanf("%s",a);
		if(a[0]=='x' && a[1]=='y' && a[2]=='z'){
			break;
		}s
		lessWords(a,b);
	}
	return 0;
}
	
