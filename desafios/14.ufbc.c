#include <stdio.h>

int main()
{

    float number;
    printf("Digite um numero: ");
    scanf("%f", &number);

    int int_part = (int)number;
    float frac_part = number - int_part;

    printf("Parte inteira: %d\n", int_part);
    printf("Parte fracionaria: %.2f\n", frac_part);

    return 0;
}

