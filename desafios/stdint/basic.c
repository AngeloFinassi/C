#include <stdio.h>
#include <stdint.h>

int32_t sum(int32_t a, int32_t b);
float calculate_average(uint16_t array[], uint32_t size);

int main(void)
{
    printf("Two values to sum\n");

    int n1, n2;
    printf("n1: ");
    scanf("%i", &n1);

    printf("n2: ");
    scanf("%i", &n2);

    uint16_t myArray[] = {10, 20, 30, 40, 50};
    uint32_t size_Array = (sizeof(myArray) / sizeof(myArray[0]));

    int result_soma = sum(n1, n2);
    printf("Sum: %i\n", result_soma);

    float average = calculate_average(myArray, size_Array);
    printf("Average: %.2f\n", average);

    return 0; // Adicione este retorno no final da função main
}

int32_t sum(int32_t a, int32_t b)
{
    return a + b;
}

float calculate_average(uint16_t array[], uint32_t size)
{
    uint32_t s = 0;
    for (int i = 0; i < size; i++)
    {
        s += array[i];
    }
    return (float)s / size;
}
