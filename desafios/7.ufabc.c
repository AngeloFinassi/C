#include <stdio.h>
#include <stdlib.h>
#include <time.h> // 👈 Necessário para inicializar o gerador aleatório (srand)

// --- CORREÇÕES NA FUNÇÃO GerarNumero ---

// 1. O tipo de retorno deve ser int* (ponteiro) e NÃO int
// 2. Usar 'n' como nome para o número de elementos é comum, mas 'times' funciona.
int *GerarNumero(int times, int a, int b) {
    
    // CORREÇÃO CRÍTICA 1: Alocação Dinâmica (Heap)
    // Usamos malloc para que o vetor não seja destruído ao sair da função.
    int *val = (int *)malloc(times * sizeof(int));
    
    if (val == NULL) {
        // Verifica se a alocação falhou
        return NULL; 
    }

    // CORREÇÃO CRÍTICA 2: Cálculo do Intervalo (range)
    // Para incluir o limite superior 'b', o tamanho do intervalo deve ser b - a + 1.
    int range = b - a + 1; 
    
    for(int i = 0; i < times; i ++){
        // Fórmula correta: (rand() % range) + a
        val[i] = (rand() % range) + a;
    }

    // Retornamos o ponteiro para o bloco de memória alocado (Heap)
    return val;
}

// Função auxiliar para imprimir o vetor completo
void ImprimirVetor(int *vetor, int tamanho) {
    if (vetor == NULL) {
        printf("Erro ao gerar o vetor.\n");
        return;
    }
    printf("Vetor gerado: [");
    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);
        if (i < tamanho - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    // CORREÇÃO ESSENCIAL: Inicializa a semente aleatória APENAS UMA VEZ
    // Isso garante que os números gerados sejam diferentes a cada execução.
    srand(time(NULL)); 
    
    int times = 0;
    printf("Digite o número de elementos (n): ");
    scanf("%d", &times);

    int num_a = 0;
    printf("Digite o limite inferior (a): ");
    scanf("%d", &num_a);

    int num_b = 0;
    printf("Digite o limite superior (b): ");
    scanf("%d", &num_b);
     
    // num_random recebe o endereço (ponteiro) do vetor criado no Heap
    int *num_random = GerarNumero(times, num_a, num_b);

    // CORREÇÃO CRÍTICA 3: Imprimir o Vetor
    // Não se usa %d para imprimir um vetor. Chamamos a função auxiliar.
    ImprimirVetor(num_random, times);
    
    // CORREÇÃO FINAL: Libera a memória alocada por malloc()
    if (num_random != NULL) {
        free(num_random);
    }
    
    return 0;
}