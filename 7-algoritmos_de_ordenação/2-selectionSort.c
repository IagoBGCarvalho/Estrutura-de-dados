#include <stdio.h>
#include <stdlib.h>

// Selection Sort:

// Este algoritmo divide o array em duas partes: a ordenada e a não ordenada
// Irá comparar o número analisado com todos os seus números seguintes, e quando achar um menor do que ele, troca os número de posição.

void selectionSort(int v[], int n){
    int i, j, menor, troca;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
            menor = j;
        }
    }
    if(i != menor){
        troca = v[i];
        v[i] = v[menor];
        v[menor] = troca;
    }
    }
}