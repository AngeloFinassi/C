#include <stdio.h>

int main()
{

    int a, b = 0;
    printf("Digite numero a: ");
    scanf("%d", &a); 
    
    printf("Digite numero b: ");
    scanf("%d", &b);

    if (a != 0)
    {   
        int x = -b/a;
        printf("x = %d", x);
        return 0;
    }
    if (b == 0){
        printf("infinitas solucoes");
        return 0;
    }

    printf("nao ha solucao para essa equacao");
    return 0;
}

