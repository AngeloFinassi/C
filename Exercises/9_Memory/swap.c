#include <stdio.h>

void swap(int *a, int *b); // Declaração da função swap com argumentos ponteiros

int main(void)
{
    int x = 1;
    int y = 2;
    
    printf("x - %d, y - %d\n", x, y);

    swap(&x, &y); // Passagem dos endereços de memória das variáveis x e y

    printf("x - %d, y - %d\n", x, y);

    return 0;
}

void swap(int *a, int *b) // Definição da função swap com argumentos ponteiros
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
}
