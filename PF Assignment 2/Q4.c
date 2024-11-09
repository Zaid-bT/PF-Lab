#include <stdio.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_STRING_LENGTH 100

void sortString(char *str) {
	int i,j;
    int len = strlen(str);
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

void groupAnagrams(char transactions[MAX_TRANSACTIONS][MAX_STRING_LENGTH], int count) {
    int i,j;
	char sorted[MAX_TRANSACTIONS][MAX_STRING_LENGTH]; 
    int grouped[MAX_TRANSACTIONS] = {0}; 
    for (i = 0; i < count; i++) {
        strcpy(sorted[i], transactions[i]);
        sortString(sorted[i]); 
    }
    printf("Grouped Anagrams:\n");
    for (i = 0; i < count; i++) {
        if (grouped[i] == 0) { 
            printf("[");
            for (j = 0; j < count; j++) {
                if (grouped[j] == 0 && areAnagrams(sorted[i], sorted[j])) {
                    printf("'%s'", transactions[j]);
                    grouped[j] = 1; 
                    if (j < count - 1) {
                        printf(", ");
                    }
                }
            }
            printf("]\n");
        }
    }
}

int areAnagrams(char *str1,char *str2) {
    return strcmp(str1, str2) == 0; 
}

int main() {
    char transactions[MAX_TRANSACTIONS][MAX_STRING_LENGTH] = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };
    int count = 6; 
    groupAnagrams(transactions, count);

    return 0;
}

