#include <stdio.h>
#include <string.h>
int add(int a, int b){
    return a + b;
}

int main(){
    //if i want to convert the number base 
    // put (float) number, before the number
    //when I say what type is int, i use the (float)
    // before alguma conta 
    //z = a / b -> 1 / 3 = 0
    //z = (float)a / (float)b -> 1/ 3 = 0.3333333

    //printf("%.5f", z); the '.5' say the number after the dot
    int z = add(2, 5);
    printf("%i", z);
}