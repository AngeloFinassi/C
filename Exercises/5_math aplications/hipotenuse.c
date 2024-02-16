#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    // is a large float = double
    double co, ca, h;

    printf("Whats the value of co? ");
    scanf("%lf", &co);

    printf("Whats the value of ca? ");
    scanf("%lf", &ca);

    h = sqrt(pow(co, 2) + pow(ca, 2));

    printf("\nthe value of the hypotenuse of your triangle is? %lf\n", h);
}