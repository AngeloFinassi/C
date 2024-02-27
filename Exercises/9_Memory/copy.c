#include <stdio.h>
#include <string.h>
#include <ctype.h>

//malloc() retorna um espaço na memoria, maloc(strlen(s)) vai retornar um espaço na memoria com o tamanho do s

//free [e o malloc -1], pq ele apaga aquele espaço de memoria que vc tinha requisitado pelomaloc, devolve para o pc

int main() {
    char s[100], t[100];

    // Recebe a string de entrada
    printf("Digite uma string: ");
    fgets(s, sizeof(s), stdin);


    // Copia a string para outra variável
    strcpy(t, s);

    // Transforma a string t em maiúsculas
    for (int i = 0; t[i]; i++)
        t[i] = toupper(t[i]);

    // Imprime as duas strings
    printf("String original: %s\n", s);
    printf("String em maiusculas: %s\n", t);

    return 0;
}
