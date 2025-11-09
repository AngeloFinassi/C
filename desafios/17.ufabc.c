#include <stdio.h>

int DetCalc(int matriz[3][3])
{
    int det = 0;

    double det_prim =  0.0;
    double det_seg =  0.0;
    
    det_prim = matriz[0][0] * matriz[1][1] * matriz[2][2];
    det_prim += matriz[0][1] * matriz[1][2] * matriz[2][0];
    det_prim += matriz[0][2] * matriz[1][0] * matriz[2][1];

    det_seg = matriz[0][2] * matriz[1][1] * matriz[2][0];
    det_seg += matriz[0][0] * matriz[1][2] * matriz[2][1];
    det_seg += matriz[0][1] * matriz[1][0] * matriz[2][2];

    det = (int)det_prim - (int)det_seg;
    return det;
}

int main()
{

    int matriz[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0},
    };

    printf("Determinante: %d\n", DetCalc(matriz));

    return 0;
}

