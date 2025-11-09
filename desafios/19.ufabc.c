#include <stdio.h>
#include <string.h>

void TiraVogal(char Vetor[], char saida[])
{   
    char* Vogais = "aeiouAEIOU";
    int j = 0;

    for (size_t i = 0; i < strlen(Vetor); i++)
    {
        if (strchr(Vogais, Vetor[i]) == NULL)
        {
            saida[j] = Vetor[i];
            j++;
        }
    }

    saida[j] = '\0';
}

int main()
{

    char Vetor[] = "abcefghijklmnopqrstuvwxzy";
    char resultado[100];
    TiraVogal(Vetor, resultado);
    printf("%s", resultado);

    return 0;
}

