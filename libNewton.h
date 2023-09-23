#ifndef _LIBNEWTON_H_
#define _LIBNEWTON_H_

#include "utils.h"

/**
 * Funcao que aloca espaco para uma matriz triangular com diagonal invertida.
 *  Tipo isso aqui:
 *  ____
 *  |  /
 *  | /
 *  |/
 *
 * Usa n como o número maximo de elementos na primeira linha/coluna
 * Retorna a mesma.
 */
real_t** alocaTriangular(int_t n);

/**
 * Funcao que libera o espaco da matriz triangular 2d de n colunas.
 */
void liberaTriangular(real_t** matriz, int_t n);

/**
 * Funcao que realiza o calculo do polinomio de Newton.
 * Recebe vetores dos n pontos x e y e o calcula com base em pontoX.
 * Ao final retorna o valor do polinomio.
 */
real_t pNewton(int_t n, real_t pontoX, real_t* tabela);

/**
 * Funcao que monta as diferencas divididas no alcance [xindiceA..xindiceB] a partir de uma ordem  e as salva na matriz triangular.
 * Retorna o valor da funcao de ordem n.
 */
real_t montaDiffDivididas(int_t ordem, int_t indiceA, int_t indiceB, real_t** diff_divididas, real_t* tabela);

#endif