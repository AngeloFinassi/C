#include <stdio.h>
#include <string.h>

int MaioSeq(char frase[], char result[])
{
    int count = 1;
    int max_count = 1;
    int best_start_index = 0;

    for (size_t i = 1; i < strlen(frase); i++)
    {
        if (frase[i] == frase[i - 1])
        {
            count++;
        }
        else
        {   
            if (count > max_count)
            {   
                //qualquer sec, primeira seg, terc... n sendo a ultima
                best_start_index = i - max_count;
                max_count = count;
            }
            count = 1;
        } 
    }

    //caso ultima seq é a maior
    if (count > max_count)
    {
        max_count = count;
        best_start_index = strlen(frase) - max_count;
    }

    //copia em result 
    for (int i = 0; i < max_count; i++)
    {
        result[i] = frase[best_start_index + i];
    }
    return max_count;
}

int main()
{

    char frase[100];
    printf("Digite uma frase: ");
    scanf("%99s", frase);

    char result[100];
    int max = MaioSeq(frase, result);

    printf("\nSequencia mais longa: %s\n", result);
    printf("Tamanho da sequencia: %d\n", max);

    return 0;
}

