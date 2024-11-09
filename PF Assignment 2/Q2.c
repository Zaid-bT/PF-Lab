#include <stdio.h>
#include <string.h>

#define MAX_SLOGAN_LENGTH 100

void analyzeSlogan(char *slogan) {
	int i;
    int frequency[256] = {0}; 
    for (i = 0; slogan[i] != '\0'; i++) {
        frequency[slogan[i]]++;
    }
    printf("{");
    for (i = 0; i < 256; i++) {
        if (frequency[i] > 0) {
            printf("'%c': %d, ", (char)i, frequency[i]);
        }
    }
    printf("\b\b}"); 
}

int main() {
	int i;
    char *slogans[10] = {
        "buy now",
        "save big",
        "limited offer"
    };
    for (i = 0; i < 3; i++) {
        printf("Analyzing slogan: \"%s\"\n", slogans[i]);
        analyzeSlogan(slogans[i]);
        printf("\n");
    }

    return 0;
}
