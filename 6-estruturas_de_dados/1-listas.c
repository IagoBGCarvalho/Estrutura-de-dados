#include <stdio.h>
#include <stdlib.h>

int main() {

    // Listas podem ser representadas de formas diferentes a partir de 3 aspcetos:
    // 1 - Como os elementos são inseridos/removidos
    // 2 - Tipo de alocação
    // 3 - Tipos de acesso aos elementos

    // 1 - Quanto à inserção / remoção:
    // Lista  convencional: pode ter elementos inseridos ou removidos de qualquer lugar dela

    // Fila: estrutura do tipo FIFO (First In First Out), os elementos só podem ser inseridos no final da lista e acessados ou removidos no início da lista

    // Pilha: estrutura do tipo LIFO (Last In First Out), os elementos só podem ser inseridos, acessados ou removidos do final da lista

    // 2 - Quanto a locação de memória:

    // Alocação estática: o espaço de memória é alocado no momento da compilação do programa. É necessário definir o número máximo de elementos.

    // Alocação dinâmica: É alocado em tempo de execução. A lista cresce à medida que novos elementos são adicionados.

    // 3 - Quanto ao acesso aos elementos:

    // Acesso sequencial: os elementos são armazenados de forma consecutiva na memória.

    // Acesso encadeado: cada elemento pode estar em uma área distinta da memória. É necessário que cada elemento da lista armazene, além da sua informação, o endereço de memória onde se encontra o próximo elemento. Para acessar um elemento, é preciso percorrer todos os seus antecessores primeiro.

    // Operações básicas de uma lista:

    // 1 - Criar uma lista
    // 2 - Inserir um elemento
    // 3 - Remover um elemento
    // 4 - Buscar por um elemento
    // 5 - Destruição da lista
    // 6 - Informações como tamanho ou se está cheia ou vazia

    int* ponteiro = (int *) malloc(sizeof(int));

    // Implementação do tipo da lista:

    typedef struct lista Lista;
    typedef struct listano ListaNo;

    struct lista {
        // Estrutura que apenas representa o ponteiro que aponta para o começo da lista (e para o primeiro elemento da lista). O ponteiro "prim" recebe "ListaNo*" pois precisa apontar para uma estrutura que possua o item e o endereço do próximo elemento. 
        ListaNo* prim;
    }

    struct listano {
        // Estrutura que representa os demais elementos da lista, que devem possuir, necessariamente, um elemento (item) e um ponteiro que aponta para o próximo item
        int item;
        ListaNo* prox;
    }

    // Implementação da criação da lista:
    Lista* cria(void) {
        // Função que incializa uma lista vazia.
        // A função deve ter, como tipo, a estrutura Lista, e como valor de retorno, uma lista sem elementos.
        Lista* l = (Lista*) malloc(sizeof(Lista));
        l->prim = null; // -> serve para acessar membros de uma struct através de um ponteiro
        return l;
    }

    void insere(Lista* l, int v) { // (lista, valor)
        // Este algoritmo insere novos elementos no COMEÇO da lista (lista não possuem regras de inserção)
        ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

        novo->item = v; // Insere o valor v no item
        novo->prox = l->prim; // Como o próximo nó ainda não existe, o ponteiro recebe o valor de prim (NULL)

        l->prim = novo; // Aponta o ponteiro inicial para o endereço do novo nó
    }

    void imprime(Lista* l) {
        for (ListaNo* p=1->prim; p!= NULL; p = p->prox) {
            // p começa do primeiro elemento da lista, printa enquanto p for diferente de NULL e, a cada loop, recebe o endereço do próximo item
            printf("Item = %d\n", p->item);
        }
    }

    int percorre(LIsta* l, int v) {
        for(ListaNo* p=1->prim; p != NULL; p = p->prox) {
            if (p->item == v) {
                return 1; // Encontrou!
            }
        }
        return 0; // Não achou...
    }

    void remove(Lista* l, int v) {
        ListaNo* ant = NULL; // ponteiro para elemento anterior
        ListaNo* p = l->prim; // ponteiro para percorrer a lista 
        // procura elemento na lista guardando anterior 
        while (p != NULL && p->item != v) {
        ant = p;
        p = p->prox;
        }
        if (p != NULL) { // verifica se achou elemento 
        if (ant == NULL) { // retira elemento do início 
        l->prim = p->prox;
        }else { // retira elemento do meio da lista 
        ant->prox = p->prox;
        }
        free(p); // libera elemento ( nó )
        }
    }



    return 0;
}