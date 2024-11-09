#include <stdio.h>
int main() {
    int n,i,j;
    printf("Enter number: ");
    scanf("%d", &n);
    for(i=n;i>=1;i--){
        for(j=0;j<n-i;j++)
            printf(" ");
        for(j=i;j>=1;j--)
            printf("%d ",j);
        printf("\n");
    }
    for(i=2;i<=n;i++){
        for(j=0;j<n-i;j++)
            printf(" ");
        for(j=i;j>=1;j--)
            printf("%d ",j);
        printf("\n");
    }
    return 0;
}
