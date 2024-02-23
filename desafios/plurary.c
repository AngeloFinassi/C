#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{   
    //Gets 3 name and save in name_input
    int n_candidate = 3;
    char name_input[n_candidate][10];
    char name[50];

    //To save vots and compare
    char vote[50];
    int scores[3];

    for (int i = 0; i < n_candidate; i++)
    {   
        //for acess each name its necessary use a for to
        printf("Candidate %d :", i);
        scanf("%s", &name);
        strcpy(name_input[i], name);

        scores[i] = 0;
    }

    for (int j = 0; j < n_candidate; j++)
    {
        //Gets the vots at a 'vote'
        printf("\nVote %d:", j);
        scanf("%s", &vote);

        //Compare if one candidate recieved a vote
        for (int y = 0; y < n_candidate; y++)
        {
            if(strcmp(name_input[y], vote) == 0)
            {
                scores[y]++;
            }
        }
    }
    printf("\n");

    for (int k = 0; k < n_candidate; k++)
    {
        printf("Name %d: %s\n", k + 1, name_input[k]);
        printf("score  : %d\n", k + 1, scores[k]);
        printf("\n");
    }
}