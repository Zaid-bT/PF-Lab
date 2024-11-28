#include <stdio.h>

struct Rectangle {
    float length;
    float width;
};

int check(struct Rectangle rect) {
    return (rect.length > 0.0 && rect.length < 20.0 && rect.width > 0.0 && rect.width < 20.0);
}

float calculatePerimeter(struct Rectangle rect) {
    if (check(rect)) {
        return 2 * (rect.length + rect.width);
    } else {
        printf("Invalid dimensions. Length and width must be between 0.0 and 20.0.\n");
        return -1;
    }
}

float calculateArea(struct Rectangle rect) {
    if (check(rect)) {
        return rect.length * rect.width;
    } else {
        printf("Invalid dimensions. Length and width must be between 0.0 and 20.0.\n");
        return -1;
    }
}

int main() {
    struct Rectangle rect;

    printf("Enter length of the rectangle: ");
    scanf("%f", &rect.length);

    printf("Enter width of the rectangle: ");
    scanf("%f", &rect.width);

    if (check(rect)) {
        printf("The perimeter of the rectangle is: %.2f\n", calculatePerimeter(rect));
        printf("The area of the rectangle is: %.2f\n", calculateArea(rect));
    } else {
        printf("Invalid input. Length and width must be greater than 0.0 and less than 20.0.\n");
    }

    return 0;
}

