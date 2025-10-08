#include <stdio.h>

int Maior(int num[], int indice){

    if (indice == 0) return num[indice];

    else{
        int max = Maior(num, indice - 1);

        if (num[indice] > max) {
            return num[indice];

        } else {
            return max;
        }
    }
    
}

int main()
{   
    int max;
    int tamanho = 50;
    int vars[50] = {1,2,3,4,5};
    

    max = Maior(vars, tamanho - 1);
    printf("\nO maior numero e: %d\n", max);
    
    
    return 0;
}


