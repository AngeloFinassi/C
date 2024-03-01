#include <stdio.h>

int con_vogal(char string[]);

int main(void)
{
    char word[100];
    printf("Write a string: ");
    fgets(word, sizeof(word), stdin);

    int answer = con_vogal(word);
    printf("\nYou Wrote: %s\nAnd have %d vogals", word, answer);
    return 0;
}

int con_vogal(char string[])
{
    int vogal = 0;
    while (*string != '\0')
    {
        if (*string == 'A' || *string == 'E' || *string == 'I' || *string == 'O' || *string == 'U' || *string == 'a' || *string == 'e' || *string == 'i' || *string == 'o' || *string == 'u')
        {
            vogal++;
        }
        string++;
    }
    return vogal;
}