#include "stdio.h"

int main(void)
{
    int N;
    int numero = 1;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("%d ", numero);
            numero++;
        }
        printf("\n");
    }

    return 0;
}