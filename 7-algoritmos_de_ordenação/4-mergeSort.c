#include <stdio.h>
#include <stdlib.h>
#include <math.h> // Necessário para floor()

// Merge Sort divide, recursivamente, o array em duas partes até que cada posição
// dele seja considerada como um array de um único elemento.

// Na ida da recursão, irá divir tudo, e na volta irá ordenar.

// Ao final, irá combinar tudo em um array só.

void mergeSort(int v[], int inicio, int fim) {
    int meio = floor((fim + inicio) / 2);

    if (inicio < fim) {
        // 1. Divisão
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);

        // 2. Conquista (a "mágica" que acontece na volta da recursão)
        merge(v, inicio, meio, fim);
    }
}

void merge(int v[], int inicio, int meio, int fim) {
    // [Bug sutil do seu código]: O tamanho ideal do vAux
    // seria (fim - inicio + 1). 
    // Alocar 'fim + 1' pode usar mais memória, 
    // mas funciona para o seu algoritmo.
    int tamanho = fim + 1;
    int vAux[tamanho]; // ATENÇÃO: Isso é um VLA (Variable Length Array)

    int i = inicio;     // Início da primeira metade
    int j = meio + 1;   // Início da segunda metade
    int k = 0;          // Índice do vetor auxiliar

    // 1. Intercala as duas metades no vAux
    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) {
            vAux[k++] = v[i++];
            // igual a vAux[k] = v[i]; k++; i++; (Seu comentário original)
        } else {
            vAux[k++] = v[j++];
        }
    }

    // 2. Copia o resto da primeira metade (se houver)
    while (i <= meio) {
        vAux[k++] = v[i++];
    }

    // 3. Copia o resto da segunda metade (se houver)
    while (j <= fim) {
        vAux[k++] = v[j++];
    }

    // 4. Copia o vetor auxiliar (que está ordenado) de volta para o vetor original 'v'
    for (i = inicio, k = 0; i <= fim; i++, k++) {
        v[i] = vAux[k]; // Esta era a linha que estava incompleta
    }
}