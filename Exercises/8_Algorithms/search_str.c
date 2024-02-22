#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char words[][10] = {"battleship", "boot", "cannon", "iron", "gold", "bronze"};

    char palavra[100];
    printf("String: ");
    scanf("%s", &palavra);

    for (int i = 0; i < 6; i++)
    {
        //This form don't word for strings
        // if (words[i] == palavra)

        if (strcmp(words[i], palavra) == 0)
        {
            printf("Found\n");
            return 0;
        }  
    }
    printf("Not Found");
    return 1;

}