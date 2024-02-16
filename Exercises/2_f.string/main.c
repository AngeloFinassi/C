#include <stdio.h>
#include <string.h>

int main(void){
    char answer[100];
    printf("What's your name?: ");
    scanf("%s", answer);

    int age = 0;
    printf("What's your Age");
    scanf("%d", age);
    printf("hello, %s\n your Age is %d right?", answer, age);
}