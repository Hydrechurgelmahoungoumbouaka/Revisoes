#include "stdio.h"

#define MAXOCTAL 1001

void converteOctal(int decimal)
{
    int octal[MAXOCTAL];
    int i = 0;
    if (decimal == 0)
    {
        printf("0\n");
        return;
    }

    while (decimal != 0)
    {
        octal[i] = decimal % 8;
        decimal = decimal / 8;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", octal[j]);
    }
    printf("\n");
}

int main()
{
    int numero;
    scanf("%d", &numero);
    converteOctal(numero);

    return 0;
}