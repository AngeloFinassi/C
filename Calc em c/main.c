#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "models.h"
#include "operacoes.h"

#define MAX_INPUT 10000

// Inicialização das funções antes de seu chamado na main
void operarArquivo(const char *nomeArquivo);
void operarTeclado(void);
int lerOpcaoSegura(void);
int validarStringNumerica(const char *str);

// Funcções para tratar leitura das variáveis
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Remove espaços no início e fim e quebra de linha
void trim(char *str) {
    char *end;

    // Remove espaços do início
    while(isspace((unsigned char)*str)) memmove(str, str+1, strlen(str));

    // Se a strinf for vazia
    if(*str == 0) return;

    // Remove espaços do fim
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    *(end+1) = 0;
}

// Valida se a string contém apenas números válidos
int validarStringNumerica(const char *str) {
    if (str == NULL || *str == '\0') return 0;

    int i = 0;
    
    // Verifica sinal opcional no início
    if (str[0] == '-' || str[0] == '+') {
        i++;
        // Verifica se não é apenas o sinal
        if (str[i] == '\0') return 0;
    }

    // Verifica se o resto são apenas dígitos
    for (; str[i] != '\0'; i++) {
        // Encontrou letra, espaço no meio ou símbolo inválido
        if (!isdigit((unsigned char)str[i])) {
            return 0;
        }
    }
    return 1;
}

// Lê uma linha inteira e garante que é um número válido
// Resolve o problema de digitar "1 2"
int lerNumeroTeclado(char *buffer, const char *mensagem) {
    printf("%s", mensagem);
    
    if (fgets(buffer, MAX_INPUT, stdin) == NULL) {
        return 0;
    }

    // Remove espaços extras e o \n
    trim(buffer); 

    if (!validarStringNumerica(buffer)) {
        printf(" -> ERRO: Entrada invalida! Digite apenas numeros inteiros (sem espaços ou letras).\n");
        return 0;
    }
    
    return 1;
}

int lerOpcaoSegura() {
    char buffer[100];
    printf("Escolha uma opcao: ");
    
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) return -1;
    trim(buffer);
    
    // Se não for dígito ou estiver vazio
    if (strlen(buffer) == 0 || !isdigit(buffer[0])) return -1;
    return atoi(buffer);
}

// Interface do menu e fluxo principal
void imprimirMenu() {
    printf("\n========================================\n");
    printf("          Calculadora - Grupo 13          \n");
    printf("========================================\n");
    printf("1. Soma (+)\n");
    printf("2. Subtracao (-)\n");
    printf("3. Multiplicao (*)\n");
    printf("4. Divisao Inteira (/)\n");
    printf("5. Modulo (%%)\n");
    printf("6. Fatorial (!)\n");
    printf("7. Carregar operandos do arquivo\n");
    printf("8. Sair\n");
    printf("========================================\n");
}

void operarTeclado() {
    char buffer1[MAX_INPUT], buffer2[MAX_INPUT];
    int opcao;
    
    imprimirMenu();
    opcao = lerOpcaoSegura();
    
    //Termina dee executar, trata erros
    if (opcao == -1) {
        printf("\nOpcao invalida! Por favor, digite um numero de 1 a 8.\n");
        return;
    }
    
    if (opcao == 8) {
        printf("Encerrando...\n");
        exit(0);
    }
    
    if (opcao < 1 || opcao > 8) {
        printf("\nOpcao inexistente.\n");
        return;
    }

    //Se passar do tratamento pula para as opções e redirecionamento pras funções

    //opcao arquivo
    if (opcao == 7) {
        char nomeArquivo[256];
        printf("Digite o nome do arquivo de entrada: ");
        if (fgets(nomeArquivo, sizeof(nomeArquivo), stdin) != NULL) {
            trim(nomeArquivo);
            operarArquivo(nomeArquivo);
        }
        return;
    }
    
    //Leitura do Primeiro Número
    //O loop garante que o usuário fique preso aqui até digitar algo válido ou cancelar
    //Mas para manter simples conforme seu fluxo, se errar, volta pro menu.
    if (!lerNumeroTeclado(buffer1, "Digite o primeiro numero: ")) {
        //Volta pro menu se falhar
        return;
    }
    
    Numero num1 = criarNumero(buffer1);
    
    //Caso Especial: Fatorial
    if (opcao == 6) {
        printf("Calculando: ");
        imprimirNumero(num1);
        printf("!\n");
        
        Numero resultado = fatorial(num1);
        printf("Resultado: ");
        imprimirNumero(resultado);
        printf("\n");
        
        liberarNumero(&num1);
        liberarNumero(&resultado);
        return;
    }
    
    //Leitura do Segundo Número
    if (!lerNumeroTeclado(buffer2, "Digite o segundo numero: ")) {
        // Como ja salvou o primeiro libera a memória antes de prosseguir com o segundo
        liberarNumero(&num1);
        return;
    }
    
    Numero num2 = criarNumero(buffer2);
    Numero resultado;
    
    printf("\nCalculando: ");
    imprimirNumero(num1);
    
    // Realiza a operação conforme a escolha
    switch (opcao) {
        case 1:
            printf(" + ");
            imprimirNumero(num2);
            printf("\n");
            resultado = somar(num1, num2);
            break;
        case 2:
            printf(" - ");
            imprimirNumero(num2);
            printf("\n");
            resultado = subtrair(num1, num2);
            break;
        case 3:
            printf(" * ");
            imprimirNumero(num2);
            printf("\n");
            resultado = multiplicar(num1, num2);
            break;
        case 4:
            printf(" / ");
            imprimirNumero(num2);
            printf("\n");
            resultado = dividir(num1, num2);
            break;
        case 5:
            printf(" %% ");
            imprimirNumero(num2);
            printf("\n");
            resultado = modulo(num1, num2);
            break;
        default:
            //Caso de segurança, não deveria chegar aqui
            liberarNumero(&num1);
            liberarNumero(&num2);
            return;
    }
    
    printf("Resultado: ");
    imprimirNumero(resultado);
    printf("\n");
    
    // Limpeza de memória se passar por tudo acima e ja ter feito as opeações
    liberarNumero(&num1);
    liberarNumero(&num2);
    liberarNumero(&resultado);
}

// Fluxo e leitura no caso do arquivo
void operarArquivo(const char *nomeArquivo) {
    FILE *entrada = fopen(nomeArquivo, "r");

    // tratamento de erro ao abrir arquivo
    if (!entrada) {
        printf("Erro ao abrir arquivo de entrada: %s\n", nomeArquivo);
        return;
    }
    
    FILE *saida = fopen("resultado.txt", "w");
    if (!saida) {
        printf("Erro ao criar arquivo de saída!\n");
        fclose(entrada);
        return;
    }
    
    char linha[MAX_INPUT];
    int linhaNum = 0;
    int operacoesProcessadas = 0;
    
    printf("Processando arquivo...\n");

    //lendo o arquivo linha por linha
    while (fgets(linha, sizeof(linha), entrada) != NULL) {
        linhaNum++;
        
        //trim simples para verificar se a linha é vazia
        char *ptr = linha;
        while (*ptr && isspace((unsigned char)*ptr)) ptr++;

        //linha vazia
        if (*ptr == '\0') continue;
        
        char buffer1[MAX_INPUT], operacao[10], buffer2[MAX_INPUT];
        
        // scanf retorna quantos itens conseguiu ler com sucesso
        int campos = sscanf(linha, "%s %s %s", buffer1, operacao, buffer2);
        
        if (campos != 3) {
            fprintf(saida, "Linha %d: Formato incorreto. Esperado: NUM OP NUM\n", linhaNum);
            printf("Aviso: Linha %d ignorada (formato invalido).\n", linhaNum);
            continue;
        }
        
        // Validação básica dos números lidos do arquivo
        if (!validarStringNumerica(buffer1) || !validarStringNumerica(buffer2)) {
             fprintf(saida, "Linha %d: Operandos invalidos (devem ser inteiros)\n", linhaNum);
             continue;
        }

        Numero num1 = criarNumero(buffer1);
        Numero num2 = criarNumero(buffer2);
        Numero resultado;
        
        fprintf(saida, "%s %s %s = ", buffer1, operacao, buffer2);
        
        int operacaoValida = 1;
        
        switch (operacao[0]) {
            // Semelhante ao operar teclado, mas no formato esperado do arquivo
            case '+': resultado = somar(num1, num2); break;
            case '-': resultado = subtrair(num1, num2); break;
            case '*': resultado = multiplicar(num1, num2); break;
            case '/': 
                // Validação de divisão por zero
                if (num2.tamanho == 1 && num2.digitos[0] == 0) {
                    fprintf(saida, "ERRO: Divisao por zero\n");
                    operacaoValida = 0;
                } else {
                    resultado = dividir(num1, num2); 
                }
                break;
            case '%': 
                if (num2.tamanho == 1 && num2.digitos[0] == 0) {
                    fprintf(saida, "ERRO: Modulo por zero\n");
                    operacaoValida = 0;
                } else {
                    resultado = modulo(num1, num2);
                }
                break;
            //Caso n encontre nenhuma operação valida
            default:
                fprintf(saida, "ERRO: Operacao desconhecida '%s'\n", operacao);
                operacaoValida = 0;
        }
        
        if (operacaoValida) {
            // Imprime no arquivo
            //struct Numero espera só o int, precisa escrever o sinal antes
            if (resultado.sinal == -1) fprintf(saida, "-");
            
            // Loop reverso para imprimir corretamente
            //seguindo padrão de guardar numeros grandes de forma invertida
            //leitura deve seguir o memsmo
            if (resultado.tamanho == 0) fprintf(saida, "0");
            else {
                for (int i = resultado.tamanho - 1; i >= 0; i--) {
                    fprintf(saida, "%d", resultado.digitos[i]);
                }
            }
            //rodou tudo fecha arquivo e liberar vars utilizadas
            fprintf(saida, "\n");
            liberarNumero(&resultado);
            operacoesProcessadas++;
        }
        
        liberarNumero(&num1);
        liberarNumero(&num2);
    }
    
    fclose(entrada);
    fclose(saida);
    
    printf("Concluido! %d operacoes processadas.\n", operacoesProcessadas);
    printf("Verifique o arquivo 'resultado.txt'.\n");
}

//Funcao principal que chama o menu e inicia o programa
int main(int argc, char *argv[]) {
    printf("========================================\n");
    printf("  Bem-vindo a Calculado do Grupo 13!    \n");
    printf("========================================\n\n");
    
    if (argc > 1) {
        printf("Modo arquivo detectado: %s\n\n", argv[1]);
        operarArquivo(argv[1]);
    } else {
        // Modo interativo
        while (1) {
            operarTeclado();
            printf("\n(Pressione ENTER para voltar ao menu)");
            limparBuffer(); 
        }
    }
    return 0;
}