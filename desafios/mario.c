#include <stdio.h>
#include <string.h>

int main(){
    int size, num_block, num_space, mem_space, mem_block;
    
    //Propt user ofr positive input
    do
    {
        printf("\nSize (1 to 8): ");
        scanf("%d", &size);
    } 
    while (size < 1);
    
    //size-by-size grid of brick
        mem_space = size;
        mem_block = 1;
        for (int i = 0; i < size; i++)
        {
            for (num_space = mem_space; num_space > 1; num_space--)
            {
                printf(" ");
            }
            for (num_block = 1; num_block <= mem_block; num_block++)
            {
                printf("#");
            }

            printf(" ");
            printf(" ");

            for (num_block = 1; num_block <= mem_block; num_block++)
            {
                printf("#");
            }
            for (num_space = mem_space; num_space > 1; num_space--)
            {
                printf(" ");
            }

            printf("\n");
            mem_space = size - (i + 1);
            mem_block++;
        }
        printf("\n");
}