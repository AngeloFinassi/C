#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 

int main()
{
    double angulo_inicial;
    double angulo_reduzido;
    int voltas;
    char sentido[20];
    char quadrante[30];

    printf("Angulo em graus: ");
    if (scanf("%lf", &angulo_inicial) != 1) {
        return 1;
    }

    if (angulo_inicial >= 0) {
        strcpy(sentido, "Anti-horario");
        voltas = (int)floor(angulo_inicial / 360.0);
    } else {
        strcpy(sentido, "Horario");
        voltas = (int)floor(fabs(angulo_inicial) / 360.0);
    }
    
    angulo_reduzido = fmod(angulo_inicial, 360.0);

    if (angulo_reduzido < 0) {
        angulo_reduzido += 360.0;
    }

    if (angulo_reduzido == 0 || angulo_reduzido == 360) {
        strcpy(quadrante, "Eixo Positivo X (0/360)");
    } else if (angulo_reduzido == 90) {
        strcpy(quadrante, "Eixo Positivo Y (90)");
    } else if (angulo_reduzido == 180) {
        strcpy(quadrante, "Eixo Negativo X (180)");
    } else if (angulo_reduzido == 270) {
        strcpy(quadrante, "Eixo Negativo Y (270)");
    } 
    else if (angulo_reduzido > 0 && angulo_reduzido < 90) {
        strcpy(quadrante, "1o Quadrante");
    } else if (angulo_reduzido > 90 && angulo_reduzido < 180) {
        strcpy(quadrante, "2o Quadrante");
    } else if (angulo_reduzido > 180 && angulo_reduzido < 270) {
        strcpy(quadrante, "3o Quadrante");
    } else {
        strcpy(quadrante, "4o Quadrante");
    }

    printf("\nAngulo reduzido: %.0lf graus\n", angulo_reduzido);
    printf("Quadrante: %s\n", quadrante);
    printf("Numero de voltas: %d\n", voltas);
    printf("Sentido: %s\n", sentido);
    
    return 0;
}