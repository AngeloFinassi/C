#include <stdio.h>
#include <string.h>

float average(int length, int array[]);
const int total = 3;

int main(){

    //Without Array
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;


    // //When I put a 3.0 than 3, the result will be a Float number, not int.
    // printf("The Average Score is: %.2f\n", (score1 + score2 + score3) / 3.0);

    //With Array Second form

    // printf("First Note: ");
    // scanf("%d", &score[0]);

    // printf("Second Note: ");
    // scanf("%d", &score[1]);

    // printf("Thirdy Note: ");
    // scanf("%d", &score[2]);

    //Normally is goos put cont variable em "maiusculo" pois chama atenção dso humans
  
    int score[total];

    for (int i = 0; i < total; i++)
    {
        printf("Note%d: ", i);
        scanf("%d", &score[i]);
    }
    

    printf("Average: %.2f", average(total, score));
    
}

float average(int length, int array[]){
    int sum = 0;
    for (int j = 0; j < length; j++)
    {
        sum =+ array[j];
        return sum / (float)length;
    }
    
}