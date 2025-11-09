#include <stdio.h>
#include <string.h>

int main()
{
    char* vogal = "aeiouAEIOU";
    char char_read[2];

    printf("Digite um caracter: ");
    scanf("%1s", char_read);

    if (strchr(vogal, char_read[0]) != NULL) {
        printf("Vogal\n");
    } else {
        printf("Consoante\n");

    }

    return 0;
}

