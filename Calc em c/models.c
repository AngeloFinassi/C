#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "models.h"

//Modelho escolhido para lidar com os números
Numero criarNumero(const char *texto) {
    Numero num;
    num.sinal = 1;
    int start = 0;
    
    // Verifica sinal
    if (texto[0] == '-') {
        num.sinal = -1;
        start = 1;
    } else if (texto[0] == '+') {
        start = 1;
    }
    
    // Remove zeros à esquerda
    while (texto[start] == '0' && texto[start + 1] != '\0') {
        start++;
    }
    
    num.tamanho = strlen(texto + start);
    num.digitos = (int*)malloc(num.tamanho * sizeof(int));
    
    if (!num.digitos) {
        printf("Erro de alocação!\n");
        exit(1);
    }
    
    // Armazena dígitos em ordem inversa, para facilitar operações com numeros grandes
    for (int i = 0; i < num.tamanho; i++) {
        num.digitos[i] = texto[start + num.tamanho - 1 - i] - '0';
    }
    
    // Se o número for zero, garante sinal positivo
    if (num.tamanho == 1 && num.digitos[0] == 0) {
        num.sinal = 1;
    }
    
    return num;
}

//Como sinal =1, se o num for negtivo para imprimir tem que adicionar '-1'
void imprimirNumero(Numero n) {
    if (n.tamanho == 0 || (n.tamanho == 1 && n.digitos[0] == 0)) {
        printf("0");
        return;
    }
    
    if (n.sinal == -1) {
        printf("-");
    }
    
    //Imprime os numeros na ordem correta
    for (int i = n.tamanho - 1; i >= 0; i--) {
        printf("%d", n.digitos[i]);
    }
}

//Libera memória alocada para o número
void liberarNumero(Numero *n) {
    if (n->digitos != NULL) {
        free(n->digitos);
        n->digitos = NULL;
    }
    n->tamanho = 0;
}

// Cria uma cópia dos números, com um arry de forma dinâmica com malloc
Numero copiarNumero(Numero n) {
    Numero copia;
    copia.tamanho = n.tamanho;
    copia.sinal = n.sinal;
    copia.digitos = (int*)malloc(n.tamanho * sizeof(int));
    
    if (!copia.digitos) {
        printf("Erro de alocacao!\n");
        exit(1);
    }
    
    for (int i = 0; i < n.tamanho; i++) {
        copia.digitos[i] = n.digitos[i];
    }
    
    return copia;
}

// Retorna: 1 se |a| > |b|, -1 se |a| < |b|, 0 se |a| = |b|
int compararAbsoluto(Numero a, Numero b) {
    if (a.tamanho > b.tamanho) return 1;
    if (a.tamanho < b.tamanho) return -1;
    
    // Mesma quantidade de dígitos, compara do mais significativo
    for (int i = a.tamanho - 1; i >= 0; i--) {
        if (a.digitos[i] > b.digitos[i]) return 1;
        if (a.digitos[i] < b.digitos[i]) return -1;
    }
    
    return 0;
}

//Anteriormente removia na leiura de usuarios no struct Numero
//Essa função trtata após as operações, limpando os restos desnecessários
void removerZerosEsquerda(Numero *n) {
    while (n->tamanho > 1 && n->digitos[n->tamanho - 1] == 0) {
        n->tamanho--;
    }
    
    // Se ficou zero, garante sinal positivo
    if (n->tamanho == 1 && n->digitos[0] == 0) {
        n->sinal = 1;
    }
}