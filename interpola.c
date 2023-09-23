#include <stdio.h>
#include <stdlib.h>
#include "libLagrange.h"
#include "libNewton.h"
#include "likwid.h"
#include "utils.h"

int main(int argc, char** argv) {
    int_t n = 0;
    // Vetores de pontos (x e y) e os pontos das abcissas
    real_t *tabela, pontoX = 0.0, *pontosX, intervalo[2],
                    tempoL, tempoN, pL = 0, pN = 0;

    if (argc != 2) {
        fprintf(stderr, "Erro nos argumentos\n");
        exit(1);
    }

    pontoX = atof(argv[1]);

    // Recebe n
    if (scanf("%ld", &n) == 0) {
        fprintf(stderr, "Erro ao ler a entrada.\n");
        exit(1);
    }

    // Aloca espaço para x e y na tabela de pontos
    if (!(tabela = (real_t*)calloc(n * 2, sizeof(real_t)))) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    // Aloca espaço para os pontos X, facilitando a funcao getMenorMaior
    if (!(pontosX = (real_t*)calloc(n, sizeof(real_t)))) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        exit(1);
    }

    // Le n pontos x,y
    for (int_t i = 0; i < n; i++) {
        if (scanf("%lf %lf", &tabela[2 * i], &tabela[(2 * i) + 1]) == 0) {
            fprintf(stderr, "Erro ao ler a entrada.\n");
            exit(1);
        }
        pontosX[i] = tabela[2 * i];
    }

    // Obtem o intervalo e verifica se o pontoX esta dentro dele
    getIntervalo(pontosX, n, intervalo);
    if (intervalo[0] > pontoX || intervalo[1] < pontoX) {
        fprintf(stderr, "Erro: o valor (xe) não pertence ao intervalo da tabela de pontos.\n");
        exit(1);
    }

    // Inicializa o marcador do likwid
    LIKWID_MARKER_INIT;

    // Funcao do polinomio de Lagrange cronometrado e contabilizado pelo likwid
    LIKWID_MARKER_START(markerName("POLINOMIO", 1));

    tempoL = timestamp();
    pL = pLagrange(n, pontoX, tabela);
    tempoL = timestamp() - tempoL;

    LIKWID_MARKER_STOP(markerName("POLINOMIO", 1));

    // Funcao do polinomio de Newton cronometrado e contabilizado pelo likwid
    LIKWID_MARKER_START(markerName("POLINOMIO", 2));

    tempoN = timestamp();
    pN = pNewton(n, pontoX, tabela);
    tempoN = timestamp() - tempoN;

    LIKWID_MARKER_STOP(markerName("POLINOMIO", 2));

    // Fecha o marcador do likwid
    LIKWID_MARKER_CLOSE;

    // Impressao dos dados obtidos.
    printf("fL(x) = %lf\n", pL);
    printf("Tempo Lagrange: %lf\n", tempoL);
    printf("fN(x) = %lf\n", pN);
    printf("Tempo Newton: %lf\n", tempoN);

    free(tabela);
    free(pontosX);
    return 0;
}