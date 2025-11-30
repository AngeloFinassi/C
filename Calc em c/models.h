#ifndef MODELS_H
#define MODELS_H

// define o dado personalizado Numero, q posteeriomente é chamado em outros files
typedef struct {
    int tamanho;
    int *digitos;
    int sinal;
} Numero;

// Funções principais 
Numero criarNumero(const char *texto);
void imprimirNumero(Numero n);
void liberarNumero(Numero *n);
Numero copiarNumero(Numero n);

// Funções auxiliares
int compararAbsoluto(Numero a, Numero b);
void removerZerosEsquerda(Numero *n);

#endif