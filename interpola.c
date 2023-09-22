#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "libLagrange.h"
#include "libNewton.h"

int main(int argc, char **argv) {
	int_t n = 0;
	// Vetores de pontos (x e y)
	real_t *tabela, pontoX = 0.0;

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

	// Le n pontos x,y
	for(int_t i = 0; i < n; i++) {
		if(scanf("%lf %lf", &tabela[2*i], &tabela[(2*i)+1]) == 0) {
			fprintf(stderr, "Erro ao ler a entrada.\n");
			exit(1);
		}
	}

	printf("\nfL(x) = %lf\n", pLagrange(n, pontoX, tabela));
	printf("\nfD(x) = %lf\n", pNewton(n, pontoX, tabela));
	free(tabela);
	return 0;
}