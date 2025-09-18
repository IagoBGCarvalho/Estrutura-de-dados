#include <stdio.h>
#include <stdlib.h>

int main(){
    int tamanho_vetor; // Variável para armazenar o tamanho da memória a ser alocada

    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &tamanho_vetor);

    int* ponteiro = (int  *) malloc(tamanho_vetor * sizeof(int)); // Cria um ponteiro int (pois deve ser do mesmo tipo que a memória a ser alocada), faz o mudança do tipo do retorno do malloc (que por default é NULL) para int e aloca "tamanho_vetor" espaços em um vetor, com cada espaço contendo o tamanho de um número inteiro (sizeof...)

    for (int i = 0; i < tamanho_vetor; i++){
        printf("Preencha o vetor %d vezes com numeros inteiros: \n", tamanho_vetor - i);
        scanf("%d", &ponteiro[i]); // A cada iteração, adiciona o número dado pelo input do usuário ao espaço de memória previamente alocada. O "&ponteiro[i]"" está alocando o valor dado a partir do começo do espaço de memória apontado por ele.
    }

    printf("Vetor preenchido: \n");

    for(int i = 0; i < tamanho_vetor; i++){
        printf("%d\n", ponteiro[i]); // Apenas exibe na tela o que foi inserido em cada espaço de memória, seguindo a mesma lógica do for anterior.
    }
    free(ponteiro); // Libera a memória para evitar vazamento e erros de compilação
    ponteiro = NULL; // Apenas uma boa pratica
    return 0;
}