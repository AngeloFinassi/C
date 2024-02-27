#include <stdio.h>
#include <string.h>

int main(void)
{
    // write ancora - w a. reading -  r
    FILE *file = fopen("phonebook.csv", "a");
    if (file == NULL)
    {
        return 1;
    }
    

    char name[100];
    printf("name: ");
    scanf("%s", name);

    char number[100];
    printf("number: ");
    scanf("%s", number);

    fprintf(file, "%s, %s\n", name, number);

    fclose(file);
}