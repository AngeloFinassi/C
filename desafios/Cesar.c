#include <stdio.h>
#include <string.h>
#include <ctype.h>

void crip(char palavra[], int key);
void decrip(char palavra[], int key);

int main()
{   
    char text_input[100];
    printf("Write a text: ");
    fgets(text_input, sizeof(text_input), stdin);

    int chave;
    printf("Write a Key: ");
    scanf("%d", &chave);

    int intention;
    printf("Do you want to criptografy ou decripitografy? 1/2: ");
    scanf("%d", &intention);

    if (intention == 1)
    {
        crip(text_input, chave);
    }
    else
    {
        decrip(text_input, chave);
    }

    printf("%s", text_input);

    return 0;
}

void crip(char palavra[], int key)
{
    for (int i = 0, n = strlen(palavra); i < n; i++)
    {   
        if (palavra[i] != '\0')
        {
            palavra[i] = palavra[i] + key;
        }
    }
}

void decrip(char palavra[], int key)
{
    for (int i = 0, n = strlen(palavra); i < n; i++)
    {
        if (palavra[i] != '\0')
        {
            palavra[i] = palavra[i] - key;
        } 
    }
}