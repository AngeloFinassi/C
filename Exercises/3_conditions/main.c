#include <stdio.h>
#include <string.h>


int main(){
    int age1;
    printf("What's your age?: ");
    scanf("%d", &age1);

    int age2;
    printf("Whats your sister age? ");
    scanf("%d", &age2);
    
    //We can use >, <, <=, >=, ==
    //or = ||, and = && , not = !
    if (age1 > age2){
        printf("Your are the older brother");
    }

    else if (age1 < age2){
        printf("Your sister is the older sister");
    }

    else{
        printf("You Have the same age as your sister");
    }
}