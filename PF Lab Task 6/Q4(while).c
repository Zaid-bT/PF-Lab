#include <stdio.h>

int main() {
    int num,total;
    printf("Enter a number (0 to stop): ");
    scanf("%d",&num);
    while(num!=0){ 
        total += num;
        printf("Enter a number (0 to stop): ");
        scanf("%d",&num);
    }
    printf("Total sum: %d\n", total);
    
    return 0;
}

