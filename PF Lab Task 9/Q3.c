#include<stdio.h>
#include<string.h>

int main(){
	char username[50];
	char password[50];
	char user[]="admin";
	char pass[]="1234";
	printf("Enter username: ");
	scanf("%s",username);
	printf("Enter password: ");
	scanf("%s",password);
	if(strcmp(user,username)==0 && strcmp(pass,password)==0){
		printf("Access granted");
	}else{
		printf("Access denied");
	}
	
	return 0;
}
