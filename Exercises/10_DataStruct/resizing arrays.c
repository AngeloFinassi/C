#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    //decalra que a lista tem para sempre 3 espaos e n mudara
    //int list[3];

    //espaço lista tera memoria suficiente para 3 grupos de bytes inteiros

    //Para redimensionar lista em C tenho que criar uma nova com 4 e ai eu pego a list que tinha 3 libero oq tinha dentro e faço ela apontar para a com 4, nesse caso a tmp, assim ela é redimensionada
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    //crio e coloco 3 valores
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    //lista temporaria
    int *tmp = malloc(4 *sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    //coloca os valores da lista em tmp
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }
    //adiciona um valor a mais em tmp
    tmp[3] = 4;

    //libero os valores da lista para n dar problema e aponto para temp, dizendo que agr ele tem um novo valor
    free(list);
    list = tmp;

    //n sei o pq mas ela esquece q só tem 3 e agr assume 4 msm n dizendo isso pelo programa
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    free(list);
    return 0;
}