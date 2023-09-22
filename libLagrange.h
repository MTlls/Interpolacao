#ifndef _LIBLAGRANGE_H_
#define _LIBLAGRANGE_H_

#include "utils.h"

/**
 * Funcao que faz os calculos necessarios para criacao do polinomio de lagrange.
 * Recebe vetores dos n pontos x e y e o calcula com base em pontoX.
 * Ao final retorna o valor do polinomio.
 * 
*/
real_t pLagrange(int_t n, real_t pontoX, real_t *tabela);


/**
 * Funcao que calcula a funcao L, sendo i o indice do i-gésimo L do polinomio.
 * Recebe:
 * Número de pontos (n);
 * O parametro x (pontoX) no qual queremos descobrir o f(x);
 * O indice do da funcao L (i), e os pontos (*x) tabelados.
 * Retorna o resultado da função.
 */
real_t calculaL(int_t n, real_t pontoX, int_t i, real_t *tabela);

#endif