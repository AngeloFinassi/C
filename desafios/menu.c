#include <stdio.h>


int main() {
    int opcao;

    printf("Menu:\n");
    printf("1. Prato A\n");
    printf("2. Prato B\n");
    printf("3. Prato C\n");
    printf("4. Prato D\n");
    printf("5. Sair\n");

    printf("\nEscolha uma opção: ");
    scanf("%d", &opcao);
    printf("\n");

    switch (opcao) {
        case 1: // Se 'opcao' for igual a 1...
            printf("Você escolheu Prato A.\n");
            break; // 'break' encerra o switch. Essencial!

        case 2: // Se 'opcao' for igual a 2...
            printf("Você escolheu Prato B.\n");
            break;

        case 3: // Se 'opcao' for igual a 3...
            printf("Você escolheu Prato C.\n");
            break;

        case 4: // Se 'opcao' for igual a 4...
            printf("Você escolheu Prato D.\n");
            break;

        case 5: // Se 'opcao' for igual a 5...
            printf("Saindo do programa. Até logo!\n");
            break;

        default:
            printf("Opção inválida! Por favor, escolha um número de 1 a 5.\n");
            break;
    }

    return 0;
}
