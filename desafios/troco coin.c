#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int value_troco;

    printf("Digite o valor do Troco: ");
    scanf("%d", &value_troco);

    int cont_50 = 0, cont_20 = 0, cont_10 = 0, cont_5= 0, cont_1 = 0;

    while(value_troco > 1)
    {
        if (value_troco >= 50)
        {
            value_troco = value_troco - 50;
            cont_50++;
        }
        else{
            if (value_troco >= 20)
            {
                value_troco = value_troco - 20;
                cont_20++;
            }
            else{
                if (value_troco >= 10)
                {
                    value_troco = value_troco - 10;
                    cont_10++;
                }
                else{
                    if (value_troco >= 5)
                    {
                        value_troco = value_troco - 5;
                        cont_5++;
                    }
                    else{
                        if (value_troco >= 1)
                        {
                            value_troco = value_troco - 1;
                            cont_1++;
                        }
                    }
                }
            }
        }
    }
    printf("%d - 50, %d - 20, %d - 10, %d - 5, %d - 1", cont_50, cont_20, cont_10, cont_5, cont_1);
}