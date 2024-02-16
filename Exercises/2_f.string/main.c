#include <stdio.h>
#include <string.h>

int main(void){
    char asnwer[100];
    printf("Whats your name? ");
    scanf("%s", &asnwer);

    int age;
    printf("What's your Age? ");
    scanf("%d", &age);

    printf("Your are %c, and have %d old", asnwer, age);
}