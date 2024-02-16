#include <stdio.h>
#include <string.h>

int main(){
    int num, result;
    printf("Write a number: ");
    scanf("%d", &num);

    //for (declare a variable; condition; How increase or decrease)
    for(int i = 0; i <= 10; i++){
        result = num * i;
        printf("| %d x %d = %d |\n", num, i, result);
    }
}