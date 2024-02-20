#include <stdio.h>
#include <string.h>

int main() {

    char string[2048];
    int sentences = 0;
    int words = 1;
    int letter = -1;
    float cri, l, s;

   //Parte que le a String e seu tamanho
    printf("Forneca uma string com espacos em branco: ");
    fgets(string, sizeof(string), stdin);//mudei aqui para modernizar. ideone ñ aceita gets
    int len = strlen(string); //só pra dar melhor performance

    //Laço que separa entre ler num de palavra
    for (int i = 0; i < len; i++)
    {
        if (string[i] == ' ')
        {
            words++;
        }
        
        if (string[i] == '.')
        {
            sentences++;
        }
        
        if (i == len - 1)
        {
            //laço que le num de letras
            for (int i = 0; i < len; i++)
            {
                if (string[i] == ' ' || string[i] == '.' || string[i] == ',')
                {
                    string[i] = string[i + 1];
                }
                else{
                    letter++;
                }
            }
        }
    }
    l = (letter / words) * 100;
    s = (sentences / words) * 100;
    cri = (0.0588 * l) - (0.296 * s) -15.8;

    printf("\n");
    printf("%f", cri);
    //printf("words %d, letter %d, sentences %d\n", words, letter, sentences);
    //printf("l - %f, s - %f", l, s);
}