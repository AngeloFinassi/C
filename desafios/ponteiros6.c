#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    printf("Quantos nomes deseja armazenar? ");
    scanf("%d", &n);
    //evita bug de ler /n e ficar string vazia
    getchar();
    //scanf deixa o Enter no buffer
    //fgets lê o Enter como se fosse a próxima string
    //getchar() remove esse Enter antes do fgets

    //ponteiros para ponteiros
    char **lista = malloc(n * sizeof(char*)); // vetor de ponteiros para ponteiros char; lista → [ ptr0 , ptr1 , ptr2 , ... , ptr(n-1) ]

    for (int i = 0; i < n; i++) {
        char temp[100];

        printf("Digite o nome %d: ", i + 1);
        //le o nome de forma temporaria
        fgets(temp, 100, stdin);
        //retorna posição do \n, e subistitui por \0
        temp[strcspn(temp, "\n")] = '\0';

        //lista[i]  → [ M  a  r  i  a  \0 ], aloca memomira exata para marcra permanentemente
        //strlen n le 0 \n ai tem q adioconar no malloc
        lista[i] = malloc(strlen(temp) + 1);
        strcpy(lista[i], temp);

        //ou seja, ela aloca os ponteiros do tamanho char, dps ele pega cada ponteiro lista[i] e faz apontar para um espaço alocado do strlen, e ai a lista tem ponteiros que apontam para string que tem espaço alocado e dps copia e imprime abaixo
    }

    //imprime tudo e libera a memória utilizada
    printf("\nNomes armazenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", lista[i]);
    }

    for (int i = 0; i < n; i++) {
        free(lista[i]);
    }
    free(lista);

    return 0;
}
