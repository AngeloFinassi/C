#include <stdio.h>

void bubleSort(int arr[], int size, int order)
{
    //crescente
    if (order == 1){
        for (int i = 0; i < size -1; i++)
        {
            for (int j = 0; j < size -1 -i; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }       
        }
    }

    //decrescente
    else {
        for (int i = 0; i < size -1; i++)
        {
            for (int j = 0; j < size -1 - i; j++)
            {
                if (arr[j] < arr[j + 1])
                {
                    int tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }       
        }
    }
}

void BiggerColumn(int matriz[3][3], int arr[], int col, int size)
{
    for (int i = 0; i < 3; i++)
    {
        arr[i] = matriz[i][col];
    }

    bubleSort(arr, size, 0);
}

int main()
{
    //var alteradas localmente
    int size = 3;
    int matriz[3][3] = {
        {3, 5, 4},
        {1, 1, 9},
        {2, 6, 5},
    };

    int ordered_items[size];

    int column;
    printf("Coluna: ");
    scanf("%d", &column);

    BiggerColumn(matriz, ordered_items, column, size);

    //resultado
    printf("Coluna Ordenada: ");
    for (int i = 0; i < size; i++)   
    {
        printf("%d ", ordered_items[i]);
    }

    return 0;
}

