#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    //It's the same thing
    // printf("%c", *s);
    // printf("%c", *(s + 1));
    // printf("%c\n", *(s + 2));
    printf("%c", s[0]);
    printf("%c", s[1]);
    printf("%c\n", s[2]);
}