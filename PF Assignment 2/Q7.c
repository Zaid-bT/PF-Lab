#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void generateArray(char array[5][5]){
	int i,j;
	srand(time(NULL));  //generates new random everytime
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			array[i][j]= rand()%(90-65+1)+65; //rand() % (max - min + 1) + min
		}
	}
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
        	printf(" %c ",array[i][j]);
    	}printf("\n");
	}
}
int searchArray(char array[5][5],char *str){
	int i,j,k,found;
	int len=strlen(str);
    for(i=0;i<5;i++){
        for(j=0;j<=5-len;j++){
            if(strncmp(&array[i][j],str,len)==0){
                return 1; 
            }
        }
    }
    for(j=0;j<5;j++){
        for(i=0;i<=5-len;i++){
            found=1;
            for(k=0;k<len;k++){
                if(array[i+k][j]!=str[k]){
                    found = 0;
                    break;
                }
            }
            if(found){
				return 1;} 
        }
    }
    return 0;  
}

int main() {
    srand(time(0));
    char array[5][5];
    char input[100];
    int score=0;
	generateArray(array);
    while(1){
       
        printf("Enter a string to search ('END' to reset,'EXIT' to finish): ");
        fgets(input,100,stdin);
        input[strcspn(input,"\n")]='\0';

        if(strcmp(input, "END") == 0){
            score=0; 
        	generateArray(array);
            continue;
        }
        if(strcmp(input, "EXIT") == 0) {
            printf("Final Score: %d\n", score);
            break; 
        }
        if(searchArray(array, input)) {
            score++;
            printf("String found! Score: %d\n", score);
        }else{
            score--;
            printf("String not found! Score: %d\n", score);
        }
    }
    return 0;
}
