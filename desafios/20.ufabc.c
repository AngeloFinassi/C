#include <stdio.h>
#include <string.h>

int MaiorSeq(char frase[], char resultado[])
{
    int max_len = 0;
    int curr_len = 1;
    int max_start_index = 0;

    for (size_t i = 1; i < strlen(frase); i++)
    {
        if (frase[i] == frase[i - 1])
        {
            curr_len++;
        }
        else
        {
            if (curr_len > max_len){
                max_len = curr_len;
                max_start_index = i - curr_len;
                
            }
            curr_len = 1;
        }
    }
    if (curr_len > max_len)
    {
        max_len = curr_len;
        max_start_index = strlen(frase) - max_len;
    }
    
    for (int c = 0; c < max_len; c++)
    {
        resultado[c] = frase[max_start_index + c];
    }
    resultado[max_len] = '\0';
    return max_len;
}

int main()
{

    char frase[] = "aabbbbccc";
    char resultado[100];
    int len = MaiorSeq(frase, resultado);
    printf("Maior sequencia: %s\n", resultado);
    printf("Tamanho: %d\n", len);
    return 0;
}

