#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{   
    char words[100];
    printf("White a word: ");
    scanf("%s", words);

    //strlen read the number of C in String
    for (int i = 0, n = strlen(words); i < n; i++)
    {
        //Form by logic + number
        // if (words[i] >= 'a' && words[i] <= 'z')
        // {   
        //     printf("%c", words[i] - 32);
        // }
        // else{
        //     printf("%c", words[i]);
        // }

        //Form by 
        printf("%c", toupper(words[i]));
    }
    return 0;
}