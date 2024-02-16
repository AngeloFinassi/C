#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    bool repeat = true;
    //while repeat a code infinite time witch a condition
    while (repeat)
    {
    int num, result, want;

    printf("\nWrite a number: \n");
    scanf("%d\n", &num);

    for(int i = 0; i <= 10; i++){
        result = num * i;
        printf("| %d x %d = %d |\n", num, i, result);
    }

    printf("\n Do you want to repeat? 1/0: ");
    scanf("%d\n", &want);

    if (want == 1){
        repeat = true;
    }
    else{
        repeat = false;
    }
    } 
}