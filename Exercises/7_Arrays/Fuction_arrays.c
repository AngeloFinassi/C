#include <stdio.h>
#include <string.h>

void convert_M(char word[]);
void n_space(char word[]);

int main() {
    char string[100];

    printf("Write a string: ");
    fgets(string, sizeof(string), stdin);

    n_space(string);
    
    printf("\nThe Output String is: %s\n", string);
    
    return 0;
}

void convert_M(char word[]){
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (word[i] >= 'a' && word[i <= 'z'])
        {
            word[i] = word[i] - 32;
        }
    }
}

void n_space(char word[]){
    for (int i = 0, n = strlen(word), j = 0; i < n; i++)
    {
        if (word[i] != ' ')
        {
            word[j] = word[i];
            j++;
        }   
    }
}