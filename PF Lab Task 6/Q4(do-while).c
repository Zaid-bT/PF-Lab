#include <stdio.h>

int main(){
    int num,total;
    do {
        printf("Enter a number (0 to stop): ");
        scanf("%d",&num);
        total += num; 
    } while (num != 0);
    printf("Total sum: %d\n", total);
    
    return 0;
}
