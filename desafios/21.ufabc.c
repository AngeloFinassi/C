#include <stdio.h>
#include <string.h>

void CompRemove(char frase[], char frase2[])
{
    int j = 0;
    int i = 0;

    while(frase2[i] != '\0')
    {
        if (strchr(frase, frase2[i]) == NULL)
        {
            //imverter aqui faz ele buscar oq é igual
            frase2[j] = frase2[i];
            j++;
        }
        i++;
    }
    frase2[j] = '\0';
}

int main()
{

    char frase[20];
    printf("String 1: ");
    scanf("%19s", frase);

    char frase2[20];
    printf("String 2: ");
    scanf("%19s", frase2);

    CompRemove(frase, frase2);
    printf("Resultado: %s\n", frase2);

    return 0;
}

