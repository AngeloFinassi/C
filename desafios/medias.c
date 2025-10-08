#include <stdio.h>

int main()
{   
    float peso1, peso2, peso3, media, nota1, nota2, nota3;

    printf("Digite a nota 1 e seu peso: ");
    scanf("%f %f", &nota1, &peso1);

    printf("Digite a nota 2 e seu peso: ");
    scanf("%f %f", &nota2, &peso2);

    printf("Digite a nota 3 e seu peso: ");
    scanf("%f %f", &nota3, &peso3);

    media = (nota1*peso1 + nota2*peso2 + nota3*peso3) / (peso1 + peso2 + peso3);

    printf("\nA media ponderada e %.1f ", media);
    
    return 0;
}
