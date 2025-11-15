#include <stdio.h>

struct faces_count{
    int face;
    int count;
};

int main()
{
    int N;
    printf("Numero de lancamentos: ");
    scanf("%d", &N);

    int size = 20;
    int face[] = {6,5,5,4,4,3,3,2,2,2,2,2,1,1,1,1,1,1,1,1};
    struct faces_count faces[7] = {0};

    for (int i = 0; i < N; i++)
    {
        int random_number = rand() % size;
        
        if (faces[face[random_number]].face == 0)
        {
            faces[face[random_number]].face = face[random_number];
        }  
        faces[face[random_number]].count += 1;
    }

    for (int i = 1; i <= 6; i++)
    {
        faces[i].count = ((float)faces[i].count / (float)N) * 100;
    }
    

    printf("Face\tQuantidade\n");
    for (int i = 1; i <= 6; i++)    
    {
        printf("%d\t%d%%\n", faces[i].face, faces[i].count);
    }
    return 0;
}

