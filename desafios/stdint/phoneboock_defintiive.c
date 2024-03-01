#include <stdio.h>
#include <stdint.h>
#include <string.h>

const int size_char = 50;

typedef struct {
    char names[50];
    int number;
} person;

int main(void) {
    int num_users = 3;
    FILE *numbers;
    person users[num_users];

    numbers = fopen("list.csv", "a"); // Abre o arquivo para escrita, substituindo qualquer conteúdo existente
    if (numbers == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    char nome_usuario[50]; // Renomeando a variável para evitar conflito com a variável da estrutura

    for (int i = 0; i < num_users; i++) {
        printf("\nUser Name: ");
        fgets(nome_usuario, size_char, stdin); 

        int number_user;
        printf("User Number: ");
        scanf("%d", &number_user);
        getchar(); // Consumindo o caractere de nova linha deixado pelo scanf anterior

        strcpy(users[i].names, nome_usuario);
        users[i].number = number_user;
    }

    // Imprime os dados dos usuários
    for (int j = 0; j < num_users; j++) {
        fprintf(numbers, "%s, %d", users[j].names, users[j].number);
        //printf("Name: %s, Number: %i\n", users[j].names, users[j].number);
    }
    
    fclose(numbers);
    return 0;
}
