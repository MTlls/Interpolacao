#include "libLagrange.h"
#include "likwid.h"
#include <math.h>
#include <stdio.h>

real_t pLagrange(int_t n, real_t pontoX, real_t *tabela) {
	real_t polinomio = 0, funcaoLagrange = 0;

	// Para cara i-esimo termo do polinomio, realiza Li * f(x)
	for(int_t i = 0; i < n; i++) {
		funcaoLagrange = calculaL(n, pontoX, i, tabela);
		polinomio += (funcaoLagrange * tabela[(2 * i) + 1]);
	}

	return polinomio;
}

/**
 * Funcao que calcula a funcao L, sendo i o indice do i-gésimo L do polinomio.
 * Recebe:
 * Número de pontos (n);
 * O parametro x (pontoX) no qual queremos descobrir o f(x);
 * O indice do da funcao L (i), e os pontos (*x) tabelados.
 * Retorna o resultado da função.
 */
real_t calculaL(int_t n, real_t pontoX, int_t i, real_t *tabela) {
	real_t l = 0, numerador = 1;

	// Define o numerador do produtorio
	for(int_t j = 0; j < n; j++) {
		numerador *= (pontoX - tabela[2 * j]);
	}

	// Divide por (x-Xi)
	l = numerador / (pontoX - tabela[2 * i]);

	// Realiza as divisoes necessarias
	for(int_t j = 0; j < n; j++) {
		if(i == j)
			continue;

		// numerador / (Xi - Xj)
		l /= (tabela[2 * i] - tabela[2 * j]);
	}

	return l;
}