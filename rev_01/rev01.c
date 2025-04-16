#include <stdio.h>
#include <math.h>

int main(void)
{
    float xSalvo, ySalvo, raioSalvo;
    float xTiro, yTiro, raioTiro;
    // leituras das coordenadas
    scanf("%f %f %f", &xSalvo, &ySalvo, &raioSalvo);
    scanf("%f %f %f", &xTiro, &yTiro, &raioTiro);

    // calcula a distancia do centro de tiro e salvo

    float distancia = sqrt((xTiro - xSalvo) * (xTiro - xSalvo) + (yTiro - ySalvo) * (yTiro - ySalvo));
    if (distancia <= (raioSalvo + raioTiro))
    {
        printf("ACERTOU\n");
    }
    else
    {
        printf("ERROU\n");
    }

    return 0;
}