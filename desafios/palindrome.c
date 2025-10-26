#include <stdio.h>
#include <string.h>

int main()
{
    int MAX_SIZE = 50;
    char v[MAX_SIZE];

    printf("Digite uma palavra: ");
    scanf("%49s", v); 
    int len = strlen(v); 

    for (int i = 0; i < len / 2; i++)
    {
        if (v[i] != v[len - 1 - i])
        {
            printf("Nao e palindromo\n");
            return 0;
        }
    }
    
    printf("E palindromo\n");
    return 0;
}


