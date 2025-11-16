#include <stdio.h>

void swap(int n1, int n2, int *p1, int *p2, int *temp)
{
    p1 = &n1;
    p2 = &n2;

    ///valor de memoria
    printf("p1: %p\n", p1);

    //valor sendo acessado
    printf("*p1: %p\n", *p1);
    

    printf("Antes da troca: n1 = %d, n2 = %d\n", *p1, *p2);

    temp = p1;
    p1 = p2;
    p2 = temp;
    printf("Depois da troca: n1 = %d, n2 = %d\n", *p1, *p2);
}

int main()
{
    int n1,n2;
    int *p1, *p2, *temp;

    printf("Digite dois numeros inteiros: ");
    scanf("%d %d", &n1, &n2);

    swap(n1,n2,p1,p2,temp);
    return 0;
}