#include <stdio.h>
#include <string.h>

int main() {
    // Array de nomes, 3 elementos com até 10 caracteres cada
    char names[3][10] = {"An", "Lu", "David"};
    // Array de números, não precisa ser bidimensional
    int numbers[3] = {123, 456, 789};

    char name[100];
    printf("String: ");
    scanf("%s", name);

    int i;
    for (i = 0; i < 3; i++) {
        if (strcmp(names[i], name) == 0) {
            printf("Found %d\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
