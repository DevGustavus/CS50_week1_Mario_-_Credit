#include <stdio.h>
#include <cs50.h>

void print_pyramid(int height);

int main(void) {
    int height = 0;

    do {
        height = get_int("Height: ");
    } while (height <= 0 || height > 8);

    print_pyramid(height);

    return 0;
}

void print_pyramid(int height) {
    for (int i = 1; i <= height; i++) {
        for (int j = height - i; j > 0; j--) {
            printf(" ");
        }

        for (int k = 0; k < i; k++) {
            printf("#");
        }

        printf("  ");

        for (int l = 0; l < i; l++) {
            printf("#");
        }

        printf("\n");
    }
}
