#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *source, *destination;
    char ch;

    source = fopen("source.txt", "r");
    if (source == NULL) {
        printf("Could not open source file\n");
        return 1;
    }

    destination = fopen("destination.txt", "w");
    if (destination == NULL) {
        printf("Could not open destination file\n");
        fclose(source);
        return 1;
    }

    while ((ch = fgetc(source)) != EOF) {
        fputc(toupper(ch), destination);
    }

    fclose(source);
    fclose(destination);
    return 0;
}

