#include <stdio.h>
#include <string.h>
 
void jogo_da_forca() {
    char palavra[100];
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    int tam = strlen(palavra);
    char sequencia[tam];
    for(int i = 0; i < tam; i++) {
        sequencia[i] = '*';
    }
    
    while (strchr(sequencia, '*') != NULL) {
        char letra;
        printf("Sequencia atual: %s\nDigite uma letra: ", sequencia);
        scanf(" %c", &letra);
        
        int encontrou = 0;
        for (int i = 0; i < tam; i++) {
            if (palavra[i] == letra && sequencia[i] == '*') {
                sequencia[i] = letra;
                encontrou = 1;
            }
        }
        
        if (!encontrou) {
            printf("A letra '%c' nao esta na palavra.\n", letra);
        }
    }
    
    printf("Parabens! A palavra e '%s'.\n", palavra);
}
 
int main() {
    jogo_da_forca();
    return 0;
}