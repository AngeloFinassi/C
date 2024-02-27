#include <stdio.h>

int main(void)
{
    // hexadecimal number 0x11 0x12 0x13
    //                    0x21 0x22 0x23
    // In the memory, like a matrix

    // for acess &, *, like in scanf
    int n = 50;

    // Be p a pointer in the memory
    int *p = &n;

    //for see the memory addres we nedd %p and &

    //just %p  - 00000032
    //%p more & - 0061FF1C
    //printf("%p\n", &n);
    //If I want to see the value of the variable use %i
    printf("%i\n", *p);

    // int x = 10;
    // int *ptr = &x; // ptr holds the address of x
    // int y = *ptr; // y will be assigned the value of x (10)
}