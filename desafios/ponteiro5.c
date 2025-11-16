#include <stdio.h>

int Sum_Pot(int vetor[], int size, int *p)
{
    int sum = 0;
    for(int i = 0; i < size; i++){
        //soma +1*sizeofint, ai avança certinho cada local com vetor[i] guardado
        sum += *(p+i);
    }
    return sum;
}


int main()
{
    int size = 10;
    int vetor[] = {1,2,3,4,5,6,7,8,9,10};
    int *p = vetor;

    int total = Sum_Pot(vetor, size, p);
    printf("Soma dos elementos: %d\n", total);
    return 0;
}