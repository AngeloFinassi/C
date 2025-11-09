#include <stdio.h>
#include <string.h>

int main()
{

    char Jog_a[20];
    char Jog_b[20]; //implica, jog_b = *Job_b[0]

    printf("Jogador A (Pedra, Papel, Tesoura): ");
    //%19s limita a leitura a 19 caracteres + '\0'
    scanf("%19s", Jog_a);

    printf("Jogador B (Pedra, Papel, Tesoura): ");
    scanf("%19s", Jog_b); 
    
    // casos de vitoria do jogador A
    if (strcmp(Jog_a, "Pedra") == 0 && strcmp(Jog_b, "Tesoura") == 0)
    {
        printf("Jogador A venceu\n");
        return 0;
    }

    else if (strcmp(Jog_a, "Papel") == 0 && strcmp(Jog_b, "Pedra") == 0)
    {
        printf("Jogador A venceu\n");
        return 0;
    }

    else if (strcmp(Jog_a, "Tesoura") == 0 && strcmp(Jog_b, "Papel") == 0)
    {
        printf("Jogador A venceu\n");
        return 0;
    }
    
    //casos de empate
    else if (strcmp(Jog_a, Jog_b) == 0)
    {
        printf("Empate\n");
        return 0;
    }

    // caso de vitoria do jogador B
    else
    {
        printf("Jogador B venceu\n");
        return 0;
    }
}

