#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Esquece isso abaixo cosnegui dps em outro dia kkk ;-;
//Não consegui fazer, tenho a porra da logica escrita na minha cbç
//mas simplismente n consigo aplicar com a sintaxe da linguagem C
//Sinceramente n quero desistir mas pqp
//todo dia que estudo essa porra me sinto burro e sem entender porra nenhuma
//agr me vejo aqui desanimado e com dor de cabeça
//mas n aprendi a mexer com essa merda
//hj 20/02/2024 terminei week 2 fzd 2 desafios e sendo derrotado
//n me falta logica e comprender o problema mas saber mexer com 
//A PORRA DESSA SINTAXE DE MERDA VTNC PORRA
// N IMPORTA QUEM VSFD
void crip(char palavra[], int key);
void decrip(char palavra[], int key);

int main()
{   
    char text_input[100];
    printf("Write a text: ");
    fgets(text_input, sizeof(text_input), stdin);

    int chave;
    printf("Write a Key: ");
    scanf("%d", &chave);

    int intention;
    printf("Do you want to criptografy ou decripitografy? 1/2: ");
    scanf("%d", &intention);

    if (intention == 1)
    {
        crip(text_input, chave);
    }
    else
    {
        decrip(text_input, chave);
    }

    printf("%s", text_input);

    return 0;
}

void crip(char palavra[], int key)
{
    for (int i = 0, n = strlen(palavra); i < n; i++)
    {   
        if (palavra[i] != '\0')
        {
            palavra[i] = palavra[i] + key;
        }
    }
}

void decrip(char palavra[], int key)
{
    for (int i = 0, n = strlen(palavra); i < n; i++)
    {
        if (palavra[i] != '\0')
        {
            palavra[i] = palavra[i] - key;
        } 
    }
}