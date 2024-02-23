#include <stdio.h>
#include <string.h>

//crio o tipo de estrutra e valores
//que vai recber .> char e int
typedef struct{
    char names[50];
    int numbers;
} person;

int main() {
    //crio um array com as caracteristicas
    //do person
    person people[3];

    //Forma errada
    // people[0].names = "An";
    // people[0].numbers = "123";

    strcpy(people[0].names, "An");
    people[0].numbers = 123;

    strcpy(people[1].names, "Lu");
    people[1].numbers = 456;

    strcpy(people[2].names, "Ju");
    people[2].numbers = 789;


    char name[100];
    printf("String: ");
    scanf("%s", name);

    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].names, name) == 0)
        {
            printf("Found %d\n", people[i].numbers);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
