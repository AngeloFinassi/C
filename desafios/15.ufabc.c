#include <stdio.h>

int main()
{

    int age = 0;
    int sum = 0;
    int count = 0;

    while (1)
    {
        printf("Digite uma idade: ");
        scanf("%d", &age);

        if (age < 0)
        {
            break;
        }

        sum += age;
        count++;
    }
    
    printf("Idade media: %d", (sum/count));
    return 0;
}

