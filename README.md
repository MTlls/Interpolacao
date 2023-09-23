feito por:
Matheus Telles Batista - GRR20211774
e Wilian Pereira dos Santos - GRR20203936

# EP-03 - Interpolação 

Este trabalho explora os métodos de Lagrange e Newton para interpolar valores em um intervalo. Além de calcular seu desempenho em termos de tempo de execução e FLOPS (operações de ponto flutuante por segundo).

## Exemplo de entrada

```
    4
    2.0 2.5
    4.9 8.2
    10.55 9
    20.32 30.7

```
para uso futuro, nomearemos um arquivo com os números acima de "entrada.in"

Também precisamos escolher um valor, Xe, para obtermos sua imagem seguindo o padrão de valor-imagem provenientes da entrada.in 

## Execução
Para executar o programa, utilize o seguinte comando no terminal:

```shell
    $ source flops.sh Xe < entrada.in
```

## Saída

A saída do programa exibe a solução do sistema obtida por cada um dos métodos, cada uma com seus respectivos tempos de execução e quantidade de operações com ponto flutuante.

## Exceções

- O método de Lagrange retorna alguma variação de NaN para casos em que o valor de Xe está contido dentro dos pontos inseridos pela entrada.in, isto é, se Xe estiver presente na primeira coluna de entrada.in, o programa não tem efeito.

- Os métodos não são boas aproximações caso os valores inseridos na entrada.in sejam equidistantes (vide fenômeno de Runge).
