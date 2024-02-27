#include <stdio.h>
#include <stdint.h>

int main(void)
{
    //Coloco as caracteristicas da variavel FILE em documento apontando seu valor
    FILE *document;

    //documento agr tem propriedade de um arquivo
    //ent crio 1 com fopen (nome, condição) w a r
    document = fopen("test1.txt", "wb");

    //Caso haja algum erro para n dar problema na memoria termino o programa
    //erro por memoria, nome, tipo, etc...
    if (document == NULL)
    {
        printf("\nHave a Problem\n");
        return 1;
    }

    //imprime coisas no arquivo fprintf(arquivo_name, text)
    fprintf(document, "This is my first Archieve in C");
    fprintf(document, "I'm editing with programin, it's crazy to me, really kkkk");

    
    return 0;
}