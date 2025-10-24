#include <stdio.h>
#include <stdlib.h>

// Uma ordenação permite que o acesso aos dados seja feito de forma mais eficiente.
// Um algoritmo de ordenação é aquele que coloca os elementos de uma dada sequência em uma certa ordem predefinida

// Algoritmos básicos de ordenação:
// 1 - Por bolha (Bubble Sort)
// 2 - Por seleção (Selection Sort)
// 3 - Por inserção (Insertion Sort)

// Bubble Sort:

// Se trata da troca de valores em posições consecutivas de um array, de modo que fiquem da forma desejada.

// Exemplo: [25][86][48][92]

// O Bubble Sort irá comparar de 2 em 2 valores. Se o da esquerda for maior que o da direita, troca eles de posição, até que o maior número fique no final da lista (na primeira vez que o algoritmo for rodado) ou na sua posição adequada. Ou seja, ao final do algoritmo, apenas o último número estará ordenado com 100% de certeza, então é preciso rodar o algoritmo diversas vezes sobre a mesma coleção para que a ordenação seja, definitivamente feita. Isso geralmente é feito utilizando um loop para o algoritmo e outro para rodar o algoritmo enquanto a coleção não estiver ordenada.

// O algoritmo irá iterar sobre a lista quantas vezes forem necessárias até que não tenha mais troca a ser feita, por isso 

// Ao final do algoritmo a lista estará assim: [25][48][86][92]

void bubbleSort(int v[], int n){
    int i, continua, aux, fim = n;
    do{
        continua = 0;
        for(i = 0; i < fim - 1; i++){ // O for continua enquanto i for menor do que fim - 1 pois, na primeira iteração, o maior elemento estará, obrigatoriamente, já em seu devido lugar
            if(v[i] > v[i+1]){
                // Se o número inspecionado for maior do que o próximo dele na lista:
                aux = v[i]; // auxiliar recebe o valor do número maior
                v[i] = v[i+1]; // O espaço que era alocado pelo número maior recebe o próximo número da lista (que é menor)
                v[i+1] = aux; // Finalmente, o próximo espaço da lista recebe o número maior
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);
}