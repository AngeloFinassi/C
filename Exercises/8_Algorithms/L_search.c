#include <stdio.h>
#include <string.h>
#include <ctype.h>

//This porgram do a Virus I don't know why
int main()
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n;
    printf("Number: ");
    scanf("%d", &n);

    for (int i = 0; i < 7; i++)
    {
        if(numbers[i] == n)
        {
            printf("Found\n");
            //return  0 to say "finish the program, the value was found"
            return 0;
        } 
    }
    printf("Not found");
    //return 0 to say (program fail)
    return 0;
}