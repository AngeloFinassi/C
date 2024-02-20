#include <stdio.h>

int main(){
    float princes[] = {5.0, 10, 15, 20, 25};

    //sizeof say the quant of byte in the array, in this case 48 bytes, so if We divie the total size per some element the answer will be the number inside of array

    // for (int i = 0; i < sizeof(princes) / sizeof(princes[0]); i++)
    // {
    //     printf("$%.2f\n", princes[i]);
    // }
    
    for (int i = 0; i < sizeof(princes) / sizeof(princes[0]); i++)
    {
        printf("$%.2f\n", princes[i]);
    }
    
}