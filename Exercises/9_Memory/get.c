#include <stdio.h>

int main(void)
{
    char s[100];
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);

    int n;
    printf("n: ");
    scanf("%i", &n);

    printf("n: %i\n", n);
}