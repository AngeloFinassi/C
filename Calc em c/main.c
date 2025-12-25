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
    // le todos chars até encontrar quebra de linha ou fim de arquivo
    // evitar bugs com scanf e fgets ou getchar
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
    printf("6. Ordenar Digitos (Quick sort)\n");
    printf("7. Ordenar n Numeros (Insertion sort)\n");
    printf("8. Carregar operandos do arquivo\n");
    printf("9. Sair\n");
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
    
    if (opcao == 9) {
        printf("Encerrando...\n");
        exit(0);
    }
    
    if (opcao < 1 || opcao > 9) {
        printf("\nOpcao inexistente.\n");
        return;
    }

    //Se passar do tratamento pula para as opções e redirecionamento pras funções

    //opcao arquivo
    if (opcao == 8) {
        char nomeArquivo[256];
        printf("Digite o nome do arquivo de entrada: ");
        if (fgets(nomeArquivo, sizeof(nomeArquivo), stdin) != NULL) {
            trim(nomeArquivo);
            operarArquivo(nomeArquivo);
        }
        return;
    }
    
    // Caso especial: Ordenação de números via insertion sort
    if (opcao == 7) {
        char buffer[MAX_INPUT];
        int qtd;

        if (!lerNumeroTeclado(buffer, "Digite a quantidade de numeros a serem ordenados: ")) {
            return;
        }

        qtd = atoi(buffer);

        if (qtd <= 0) {
            printf("Quantidade invalida\n");
            return;
        }

        Numero *vetor = malloc(qtd * sizeof(Numero));
        if (!vetor) {
            printf("Erro na alocacao da memoria\n");
            return;
        }

        for (int i = 0; i < qtd; i++) {
            printf("Digite o numero %d: ", i + 1);

            if (fgets(buffer, MAX_INPUT, stdin) == NULL) {
                for (int k = 0; k < i; k++) {
                    liberarNumero(&vetor[k]);
                }
                free(vetor);
                return;
            }

            trim(buffer);

            if (!validarStringNumerica(buffer)) {
                printf("Apenas numeros inteiros sao validos.\n");
                i--;
                continue;
            }

            vetor[i] = criarNumero(buffer);
        }

        insertionSortNumeros(vetor, qtd);

        printf("\nNumeros ordenados:\n");
        for (int i = 0; i < qtd; i++) {
            imprimirNumero(vetor[i]);
            printf("\n");
        }

        for (int i = 0; i < qtd; i++) {
            liberarNumero(&vetor[i]);
        }
        free(vetor);
        return;
    }

    //Leitura do Primeiro Número
    if (!lerNumeroTeclado(buffer1, "Digite o primeiro numero: ")) {
        //Volta pro menu se falhar
        return;
    }
    
    Numero num1 = criarNumero(buffer1);
    
    //Caso Especial: Ordenação de dígitos via quick sort
    if (opcao == 6) {
        printf("Ordenando digitos de: ");
        imprimirNumero(num1);
        printf("\n");
        
        Numero resultado = ordenarNumero(num1);
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
        
        // Cria uma cópia da linha para processar com strtok
        char linhaCopia[MAX_INPUT];
        strcpy(linhaCopia, linha);
        
        // Conta tokens e verifica se o último é 'i'
        char *tokens[1000];
        int numTokens = 0;
        char *token = strtok(linhaCopia, " \t\n");
        
        while (token != NULL && numTokens < 1000) {
            tokens[numTokens++] = token;
            token = strtok(NULL, " \t\n");
        }
        
        // Verifica se é insertion sort (último token é 'i')
        if (numTokens >= 2 && strcmp(tokens[numTokens - 1], "i") == 0) {
            
            // É uma operação de insertion sort
            int qtd = numTokens - 1; // Exclui o 'i' do final
            Numero *numeros = malloc(qtd * sizeof(Numero));
            
            if (!numeros) {
                fprintf(saida, "Linha %d: Erro de alocacao de memoria\n", linhaNum);
                continue;
            }
            
            int erro = 0;
            
            // Lê todos os números (exceto o último token que é 'i')
            for (int k = 0; k < qtd; k++) {
                // Imprime número na saída (antes da ordenação)
                fprintf(saida, "%s ", tokens[k]);
                
                // Valida se é número
                if (!validarStringNumerica(tokens[k])) {
                    fprintf(saida, "ERRO: Token invalido '%s'\n", tokens[k]);
                    erro = 1;
                    break;
                }
                
                numeros[k] = criarNumero(tokens[k]);
            }
            
            if (erro) {
                // Libera números já criados
                for (int k = 0; k < qtd; k++) {
                    liberarNumero(&numeros[k]);
                }
                free(numeros);
                continue;
            }
            
            // Imprime o 'i'
            fprintf(saida, "i = ");
            
            // Ordena os números
            insertionSortNumeros(numeros, qtd);
            
            // Imprime resultado
            for (int k = 0; k < qtd; k++) {
                if (numeros[k].sinal == -1) fprintf(saida, "-");
                if (numeros[k].tamanho == 0) {
                    fprintf(saida, "0");
                } else {
                    for (int j = numeros[k].tamanho - 1; j >= 0; j--) {
                        fprintf(saida, "%d", numeros[k].digitos[j]);
                    }
                }
                if (k < qtd - 1) fprintf(saida, " ");
            }
            fprintf(saida, "\n");
            
            // Libera memória
            for (int k = 0; k < qtd; k++) {
                liberarNumero(&numeros[k]);
            }
            free(numeros);
            
            operacoesProcessadas++;
            continue;
        }

        // Variáveis temporárias para a tentativa de leitura
        char t_tok1[MAX_INPUT], t_tok2[MAX_INPUT], t_tok3[MAX_INPUT];
        int campos;
        
        Numero resultado;
        int operacaoValida = 1;
        
        // --- 1. TENTA LER FORMATO BINÁRIO (3 TOKENS: NUM OP NUM) ---
        // Prioriza a leitura binária para resolver o conflito com números grandes.
        campos = sscanf(linha, "%s %s %s", t_tok1, t_tok2, t_tok3);

        if (campos == 3) {
            // É uma operação binária, agora precisamos garantir que o TOKEN 2 é um operador
            
            if (t_tok2[0] == '+' || t_tok2[0] == '-' || t_tok2[0] == '*' || t_tok2[0] == '/' || t_tok2[0] == '%') {
                
                // Formato Binário Válido
                if (!validarStringNumerica(t_tok1) || !validarStringNumerica(t_tok3)) {
                     fprintf(saida, "Linha %d: Operandos invalidos (devem ser inteiros)\n", linhaNum);
                     continue;
                }

                Numero num1 = criarNumero(t_tok1);
                Numero num2 = criarNumero(t_tok3);
                
                fprintf(saida, "%s %s %s = ", t_tok1, t_tok2, t_tok3);
                
                switch (t_tok2[0]) {
                    case '+': resultado = somar(num1, num2); break;
                    case '-': resultado = subtrair(num1, num2); break;
                    case '*': resultado = multiplicar(num1, num2); break;
                    case '/': 
                        if (num2.tamanho == 1 && num2.digitos[0] == 0) {
                            fprintf(saida, "ERRO: Divisao por zero\n");
                            operacaoValida = 0;
                        } else { resultado = dividir(num1, num2); }
                        break;
                    case '%': 
                        if (num2.tamanho == 1 && num2.digitos[0] == 0) {
                            fprintf(saida, "ERRO: Modulo por zero\n");
                            operacaoValida = 0;
                        } else { resultado = modulo(num1, num2); }
                        break;
                    default:
                        // Este caso não deve ocorrer devido ao 'if' anterior
                        fprintf(saida, "ERRO: Operacao desconhecida '%s'\n", t_tok2);
                        operacaoValida = 0;
                }
                
                if (operacaoValida) {
                    if (resultado.sinal == -1) fprintf(saida, "-");
                    if (resultado.tamanho == 0) fprintf(saida, "0");
                    else {
                        for (int i = resultado.tamanho - 1; i >= 0; i--) {
                            fprintf(saida, "%d", resultado.digitos[i]);
                        }
                    }
                    fprintf(saida, "\n");
                    liberarNumero(&resultado);
                    operacoesProcessadas++;
                }
                
                liberarNumero(&num1);
                liberarNumero(&num2);
                
            } else {
                // 3 tokens, mas o token do meio não é um operador.
                goto formato_invalido;
            }

        } 
        
        // --- 2. TENTA LER FORMATO QUICKSORT (2 TOKENS: OP NUM ou NUM OP) ---
        else if (campos == 2) {
            
            // Tentativa de leitura no formato OP NUM (antigo: quicksort 123)
            int is_qs_op_num = (strcmp(t_tok1, "quicksort") == 0);
            
            // Tentativa de leitura no formato NUM OP (novo: 123 o)
            int is_qs_num_op = (strcmp(t_tok2, "o") == 0);
            
            if (is_qs_op_num || is_qs_num_op) {
                
                char *num_str;
                char *op_str;
                
                // Determina qual token é o número e qual é o operador
                if (is_qs_op_num) {
                    op_str = t_tok1;
                    num_str = t_tok2;
                } else { // is_qs_num_op
                    op_str = t_tok2;
                    num_str = t_tok1;
                }
                
                if (!validarStringNumerica(num_str)) {
                    fprintf(saida, "Linha %d: Operando invalido para quicksort (deve ser inteiro)\n", linhaNum);
                    printf("Aviso: Linha %d ignorada (operando invalido para quicksort).\n", linhaNum);
                    goto fim_linha;
                }
                
                Numero num1 = criarNumero(num_str);
                
                fprintf(saida, "%s %s = ", num_str, op_str); // Imprime na ordem correta
                resultado = ordenarNumero(num1);
                
                // Imprime no arquivo o resultado
                if (resultado.sinal == -1) fprintf(saida, "-");
                if (resultado.tamanho == 0) fprintf(saida, "0");
                else {
                    for (int i = resultado.tamanho - 1; i >= 0; i--) {
                        fprintf(saida, "%d", resultado.digitos[i]);
                    }
                }
                
                fprintf(saida, "\n");
                liberarNumero(&num1);
                liberarNumero(&resultado);
                operacoesProcessadas++;
                goto fim_linha;
            } else {
                goto formato_invalido;
            }
        } 
        
        // --- 3. FORMATO INVÁLIDO OU OUTROS ERROS ---
        else {
            formato_invalido:
            fprintf(saida, "Linha %d: Formato incorreto. Esperado: NUM OP NUM, quicksort NUM ou NUM o ou i NUM1 NUM2 ...\n", linhaNum);
            printf("Aviso: Linha %d ignorada (formato invalido).\n", linhaNum);
        }
        
        fim_linha:; // Label para pular para o fim do processamento da linha
    }
    
    fclose(entrada);
    fclose(saida);
    
    printf("Concluido! %d operacoes processadas.\n", operacoesProcessadas);
    printf("Verifique o arquivo 'resultado.txt'.\n");
}


int main(int argc, char *argv[]) {
    printf("========================================\n");
    printf("  Bem-vindo a Calculadora do Grupo 13!    \n");
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