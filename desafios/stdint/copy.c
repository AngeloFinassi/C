#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(void)
{
    FILE *original;
    FILE *copied;
    BYTE b;
    
    //cria dois files com leitura e escrita em bytes rb, wb
    original = fopen("original.txt", "rb");
    copied = fopen("copied.txt", "wb");

    //isso aq ja sabe ne burrão?
    if (original == NULL)
    {
        printf("\nHave a Problem\n");
        return 1;
    }
    fprintf(original, "original");


    //enquanto estiver lendo o arquivo salva no local b, por acaso tem 8 bits
    //salva bits do tamanho de b com 1 bits por vez, copiando do file original
    //cada vez que carrega um bit ele escreve com fwrite
    while (fread(&b,  sizeof(b), 1, original))
    {
        //printf("%d", &b); tendi foi nada garai kkkkkk
        fwrite(&b, sizeof(b), 1, copied);
    }
    return 0;
}