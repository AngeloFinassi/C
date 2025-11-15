#include <stdio.h>
#include <stdlib.h>

int main()
{
    int quantity = 2;
    int *vetor = malloc(quantity * sizeof(int));
    int numbers = 0;

    int n;
    printf("Enter integers (-1 to exit):\n");

    while(1){
        scanf("%d", &n);
        if(n == -1){
            break;
        }
        if(numbers >= quantity){
            quantity *= 2;
            vetor = realloc(vetor, quantity * sizeof(int));
        }
        vetor[numbers] = n;
        numbers++;
    }
    
    printf("You entered:\n");
    for(int i = 0; i < numbers; i++){
        printf("%d\n", vetor[i]);
    }
}

