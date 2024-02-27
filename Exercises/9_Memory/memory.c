#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //mesma coisa que estar num computador antigo
    //sizeooff retornara o valor correto o padrão do tamanho
    //embora int = 4bits nem sempre né pai

    //ao 3* fazemos virar um array
    //pois tem 3 vezes o tamanho padrão
    int *x = malloc(3 * sizeof(int));

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    //frre your memory for don't spend a blocks of memory
    free(x);
}