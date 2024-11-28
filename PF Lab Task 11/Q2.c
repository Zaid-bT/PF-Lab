#include <stdio.h>

int main() {
    FILE *file;
    char ch;
    int line_number = 1;

    file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    printf("%d: ", line_number);
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            line_number++;
            printf("\n%d: ", line_number);
        } else {
            putchar(ch);
        }
    }

    fclose(file);
    return 0;
}

