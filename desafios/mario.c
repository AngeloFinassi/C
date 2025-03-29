#include <stdio.h>

int main() {
    int size;

    do {
        printf("Size (1 to 8): ");
        scanf("%d", &size);
    } while (size < 1 || size > 8);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }

        printf("  ");

        for (int j = 0; j < i + 1; j++) {
            printf("#");
        }
        printf("\n");
    }
}
