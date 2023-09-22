#include "libNewton.h"

#include <stdio.h>

real_t pNewton(int_t n, real_t pontoX, real_t *tabela) {
	real_t polinomio = 0;
	real_t **diff_divididas = NULL;

	// Para as linhas da tabela fazerem a forma de uma matriz U (Menos saltos na matriz).
	diff_divididas = alocaTriangular(n);

	montaDiffDivididas(n - 1, 0, n - 1, diff_divididas, tabela);

	// Multiplicacao realizada sabendo dos termos comuns das operacoes.
	// (X - X0)(D1 + (X- X1)(D2 + ... + (X-Xn-1)(Dn)))
	for(int_t i = n - 1; i > 0; i--) {
		polinomio += diff_divididas[0][i];
		polinomio *= (pontoX - tabela[2 * (i - 1)]);
	}

	// Faltava ainda o D0
	polinomio += diff_divididas[0][0];

	liberaTriangular(diff_divididas, n);

	return polinomio;
}

real_t montaDiffDivididas(int_t ordem, int_t indiceA, int_t indiceB, real_t **diff_divididas, real_t *tabela) {
	// Ponto de parada retorna f(x)
	if(ordem == 0)
		return diff_divididas[indiceA][0] = tabela[(2 * indiceA) + 1];

	// Salva o valor na tabela de diferencas divididas e retorna esse valor. Utiliza recursao para funcionar
	diff_divididas[indiceA][ordem] =
	    (montaDiffDivididas(ordem - 1, indiceA + 1, indiceB, diff_divididas, tabela) - montaDiffDivididas(ordem - 1, indiceA, indiceB - 1, diff_divididas, tabela)) / (tabela[2 * indiceB] - tabela[indiceA * 2]);
	return (diff_divididas)[indiceA][ordem];
}

real_t **alocaTriangular(int_t n) {
	real_t **matriz = NULL;

	// n linhas.
	matriz = (real_t **)calloc(n, sizeof(real_t));

	// triangularizacao
	for(int_t i = 0; i < n; i++) {
		matriz[i] = (real_t *)calloc(n - i, sizeof(real_t));
	}

	return matriz;
}

void liberaTriangular(real_t **matriz, int_t n) {
	for(int_t i = 0; i < n; i++) {
		free(matriz[i]);
	}

	free(matriz);
}