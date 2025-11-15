#include <stdio.h>

int somar(int a, int b) { return a + b; }
int subtrair(int a, int b) { return a - b; }
int multiplicar(int a, int b) { return a * b; }

int main() {
    int (*operacao)(int, int);

    int escolha;
    printf("Escolha a operação:\n");
    printf("1 - Somar\n2 - Subtrair\n3 - Multiplicar\n");
    scanf("%d", &escolha);

    // aqui *operação, aponta pro codigo da função o conteudo
    // tipo *operação = &x, onde x = 10 ai *operação = 10 muda o valor
    //aqui estamos so hei operacao aponta pra essa função, e o nome é o enderço, tipo
    //operaçao -> nome da função -> conteudo do codigo
    if (escolha == 1) operacao = somar;
    else if (escolha == 2) operacao = subtrair;
    else if (escolha == 3) operacao = multiplicar;
    else {
        printf("Opcao invalida!\n");
        return 1;
    }

    int x, y;
    printf("Digite dois números: ");
    scanf("%d %d", &x, &y);

    int resultado = operacao(x, y);
    printf("Resultado: %d\n", resultado);

    return 0;
}
