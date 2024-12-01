#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validateEmail(char* email){
	int i;
    int atCount = 0;
    int dotAfterAt = 0;
    if(email == NULL || strlen(email) == 0){
        return 0;
    }
    for(i=0;email[i] != '\0';i++){
        if(email[i] == '@'){
            atCount++;
        }
        if(atCount == 1 && email[i] == '.'){
            dotAfterAt++;
        }
    }
    if(atCount == 1 && dotAfterAt == 1){
        return 1; 
    }
    return 0; 
}

int main(){
    char *email = NULL;
    size_t size = 0;
    printf("Enter an email address: ");
    getline(&email, &size, stdin);
    if(validateEmail(email)){
        printf("Valid Email\n");
    }else{
        printf("Invalid Email\n");
    }
    free(email); 
    return 0;
}

