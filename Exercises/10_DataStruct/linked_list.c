#include <stdio.h>
#include <stdlib.h>

typedef struct  node
{
    int number;
    struct node *next;
    
} node;

int main(int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 0; i < argc; i++)
    {
        //converte string para int
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if(n == NULL)
        {
            //Free memory thus far
            return 1;
        }
        n->number = number;
        n->next = list;

        list = n;
    }

    //Print whole list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }    
}