#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "libLagrange.h"
#include "libNewton.h"


int main(int argc, char **argv) {
	int_t n = 0;
	// Vetores de pontos (x e y) e os pontos das abcissas
	real_t *tabela, pontoX = 0.0, *pontosX, intervalo[2],
    tempoL, tempoN, pL = 0, pN = 0;

	pontoX = atof(argv[1]);

	// Recebe n
	if(scanf("%ld", &n) == 0) {
		fprintf(stderr, "Erro ao ler a entrada.\n");
		exit(1);
	}

	// Aloca espaço para x e y na tabela de pontos
	if(!(tabela = (real_t *)calloc(n*2, sizeof(real_t)))) {
		fprintf(stderr, "Erro ao alocar memória.\n");
		exit(1);
	}

    // Aloca espaço para os pontos X, facilitando a funcao getMenorMaior
	if(!(pontosX = (real_t *)calloc(n, sizeof(real_t)))) {
		fprintf(stderr, "Erro ao alocar memória.\n");
		exit(1);
	}

	// Le n pontos x,y
	for(int_t i = 0; i < n; i++) {
		if(scanf("%lf %lf", &tabela[2*i], &tabela[(2*i)+1]) == 0) {
			fprintf(stderr, "Erro ao ler a entrada.\n");
			exit(1);
		}
        pontosX[i] = tabela[2*i];
	}

    // Obtem o intervalo e verifica se o pontoX esta dentro dele
    getIntervalo(pontosX, n, intervalo);
    if(intervalo[0] > pontoX || intervalo[1] < pontoX) {
        fprintf(stderr, "Erro: o valor (xe) não pertence ao intervalo da tabela de pontos.\n");
        exit(1);
    }

    // Funcao do polinomio de Lagrange cronometrado.
    tempoL = timestamp();
    pL = pLagrange(n, pontoX, tabela);
    tempoL = timestamp() - tempoL;
    
    // Funcao do polinomio de Newton cronometrado.
    tempoN = timestamp();
    pN = pNewton(n, pontoX, tabela);
    tempoN = timestamp() - tempoN;

    // Impressao dos dados obtidos.
	printf("fL(x) = %lf\nfD(x) = %lf\n\n", pL, pN);
	printf("tempo Lagrange: %lf\ntempo Newton: %lf\n", tempoL, tempoN);

    free(tabela);
    free(pontosX);
	return 0;
}