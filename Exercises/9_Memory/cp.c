#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argvc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    BYTE b;
    //aonde alocar, tamnho, quant de byte, que arquivo colar
    while (fread(&b, sizeof(b), 1, src))
    {
        fwrite(&b, sizeof(b), 1, dst);
    }
   
}