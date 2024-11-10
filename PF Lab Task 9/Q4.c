#include<stdio.h>
#include<string.h>

int main(){
	int i,j;
	char search_name[20];
	char st_name[5][20]={"Alice","Harry","Charlie","Diana","Eve"};
	
	printf("Enter student name to search: ");
	scanf("%s",&search_name);
	
	for(i=0;i<5;i++){
		if(strcmp(st_name[i],search_name)==0){
			printf("Found");
			return 0;
		}
	}
	printf("Not Found");
	return 0;
}
