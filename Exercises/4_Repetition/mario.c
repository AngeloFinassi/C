#include <stdio.h>
#include <string.h>

int main(){
    int size;
    
    //Propt user ofr positive input
    do
    {
        printf("\nSize: ");
        scanf("%d", &size);
    } 
    while (size < 1);
    
    //size-by-size grid of brick
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}