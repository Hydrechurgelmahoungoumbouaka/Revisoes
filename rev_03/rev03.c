#include "stdio.h"

#define MAX_LIVROS 10001

int main(void)
{
    int N;
    scanf("%d", &N);
    int frequencia[MAX_LIVROS] = {0};
    int livros[MAX_LIVROS];

    for (int i = 0; i < N; i++)
    {
        int id;
        scanf("%d", &id);
        livros[id] = id;
        frequencia[id]++;
    }

    for (int i = 0; i < N; i++)
    {
        int id = livros[i];
        if (frequencia[id] == 1)
        {
            printf("%d ", id);
        }
    }
    printf("\n");

    return 0;
}