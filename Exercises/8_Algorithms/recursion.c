#include <stdio.h>

void draw(int n);

int main()
{
    int height = 0;
    printf("Height: ");
    scanf("%d", &height);

    draw(height);
}

void draw(int n)
{   
    //Nothinf to draw
    if (n <= 0)
    {
        return;
    }

    draw(n- 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

    // Suponha que você chamou inicialmente a função draw(3).
    // Dentro dessa chamada, ela chama draw(2).
    // Dentro da chamada draw(2), ela chama draw(1).
    // Dentro da chamada draw(1), a função agora atinge a condição de base (caso base), porque n é igual a 1. Então, ela não chama mais a si mesma recursivamente.
    // Agora, a função volta para a chamada draw(2).
    // A chamada draw(2) já executou sua parte recursiva e agora desenha uma linha de #s correspondente à altura 2.
    // Depois disso, a função volta para a chamada draw(3).
    // A chamada draw(3) já executou sua parte recursiva e agora desenha uma linha de #s correspondente à altura 3.
    // draw(n - 1);
}