#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa {
    char *nome;
    int idade;
};

int main() {
    int n;
    printf("Quantas pessoas deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); // limpa o \n do buffer

    struct Pessoa *grupo = malloc(n * sizeof(struct Pessoa));

    for (int i = 0; i < n; i++) {
        char temp[100];

        printf("Nome da pessoa %d: ", i+1);
        fgets(temp, 100, stdin);
        temp[strcspn(temp, "\n")] = '\0';

        grupo[i].nome = malloc(strlen(temp) + 1);
        strcpy(grupo[i].nome, temp);

        printf("Idade: ");
        scanf("%d", &grupo[i].idade);
        getchar();
    }

    printf("\nDados cadastrados:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d anos\n", grupo[i].nome, grupo[i].idade);
    }

    for (int i = 0; i < n; i++) {
        free(grupo[i].nome);
    }
    free(grupo);

    return 0;
}

