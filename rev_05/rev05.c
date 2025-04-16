#include "stdio.h"
#include "stdlib.h"

#define MAX 100

typedef struct
{
    int i, j;
} Posicao;

int M, N;
int mapa[MAX][MAX];
int visitado[MAX][MAX];
Posicao caminho[MAX * MAX];
int encontrado = 0, tamanho = 0;

// define a direcao do jog baixo,esquerda,direta,cima
int direcaoI[] = {-1, 1, 0, 0};
int direcaoJ[] = {0, 0, 1, -1};
char direcao[] = {'C', 'B', 'D', 'E'};

// Função para mapear a prioriddade de indice
int direcaoParaIndice(char c)
{
    for (int i = 0; i < 4; i++)
    {

        if (direcao[i] == c)

            return i;
    }
    return -1;
}

// função para buscar

void buscar(int i, int j, int xf, int yf, char *prioridade)
{
    if (i < 0 || i >= M || j < 0 || j >= N)
        return;
    if (mapa[i][j] == 1 || visitado[i][j])
        return;
    visitado[i][j] = 1;
    caminho[tamanho++] = (Posicao){i, j};

    if (i == xf && j == yf)
    {
        encontrado = 1;
        return;
    }

    for (int k = 0; k < 4 && !encontrado; k++)
    {
        int idx = direcaoParaIndice(prioridade[k]);
        int ni = i + direcaoI[idx];
        int nj = j + direcaoJ[idx];
        buscar(ni, nj, xf, yf, prioridade);
    }

    if (!encontrado)
    {
        tamanho--; // Backtrak
    }
}

int main()
{

    scanf("%d %d", &M, &N);

    for (int i = 0; i < M; i++)

        for (int j = 0; j < N; j++)

            scanf("%d", &mapa[i][j]);

    int xi, xj, xf, yj;
    scanf("%d %d %d %d", &xi, &xj, &xf, &yj);
    xi--;
    xj--;
    xf--;
    yj--; // convertando para indice 0

    char prioridade[5];
    scanf("%s", prioridade);
    buscar(xi, xj, xf, yj, prioridade);

    for (int i = 0; i < tamanho; i++)

        printf("(%d,%d)%s", caminho[i].i + 1, caminho[i].j + 1, i < tamanho - 1 ? " " : "\n");

    return 0;
}