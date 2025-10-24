#include <stdio.h>
#include <stdlib.h>

// Insertion Sort

// Começando a partir do segundo elemento da esquerda para direita, este algoritmo pega o elemento e compara com todos os elementos a sua esquerda, trocando eles de lugar até que o elemento esteja em seu devido lugar. Faz isso com todos até chegar ao final da coleção.

void insertionSort(int v[], int n){
    int i, j, atual;
    for(i = 1; i < n; i++){
        atual = v[i]; // Pega o segundo elemento a ser comparado
        for(j = i; (j > 0) && (atual < v[j-i]); j--){
            // Enquanto o número a esquerda do atual for menor do que o valor a sua esquerda, irá executar a lógica:
            v[j] = v[j - 1]; // Caso o número atual seja MENOR do que o número atrás dele, o espaço da lista irá receber o elemento do espaço de trás
        }
        v[j] = atual; // Por fim, atual irá ser atribuído ao espaço determinado pelo valor de j, irá receber i e diminuir até que o atual seja maior do que o número a sua esquerda
    }
}