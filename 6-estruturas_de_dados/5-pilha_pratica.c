#include <stdio.h>
#include <stdlib.h>

// Definições dos tipos:
typedef struct pilha Pilha;
typedef struct fila Fila;
typedef struct no No;

// O mesmo nó serve, tanto para a pilha, quanto para a fila:
struct no{
    int item;
    No* prox; // Ponteiro que aponta para o próximo elemento da estrutura
};

struct pilha{
    No* topo; // Ponteiro que aponta para o topo da pilha
};

// Funções genéricas (para pilha e fila):

int isEmpty(Pilha* p){
    /// Verifica se a estrutura está vazia
    if (p->topo == NULL){
        printf("A pilha está vazia!\n");
        return 1; // Está vazia
    }
    return 0; // Está cheia
}

void imprimir(Pilha* p){
    /// Função que imprime todos os elementos da estrutura
    if(isEmpty(p)){
        return;
    }else{
        for(No* q = p->topo; q != NULL; q = q->prox){
        // for: O ponteiro q recebe o endereço do topo da pilha, o for vai continuar enquanto q for diferente de nulo (enquanto ele não for o último elemento) e ao final de cada loop q vai receber o próximo elemento
        printf("Item da pilha: %d\n", q->item); // Imprime o item de cada elemento a cada loop
        }
    }
}

void libera(Pilha* p){
    /// Função que libera a estrutura inteira, primeiro liberando cada nó alocado
    No* aux = p->topo; // Variável auxiliar para receber o topo da estrutura
    while(aux != NULL){
        No* t = aux->prox; // Outra variável auxiliar que irá receber o próximo elemento de aux
        free(aux); // Está liberando a memória alocada na localizaçao que aux está apontando (o topo)
        aux = t; // Por fim, aux recebe t, que é o novo topo
    }
    free(p);
}

// Funções específicas da pilha:

Pilha* criaPilha(){
    /// Função que cria a estrutura da pilha
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL; // Topo instanciado (que é a mesma coisa de criar uma pilha vazia, visto a estrutura da pilha apenas possui o topo)
    return p; // Retorna o ponteio que aponta para a estrutura criada
}

void push(Pilha* p, int v){
    /// Função que insere um nó na estrutura
    No* novo = (No*)malloc(sizeof(No)); // Aloca um espaço dinamicamente com o tamanho de um nó (item e prox)
    novo->item = v; // Atribui o valor do parâmetro ao item do nó
    novo->prox = p->topo; // Como novo é novo topo, o próximo dele é o antigo topo
    p->topo = novo;
}

int pop(Pilha* p){
    /// Função que remove um nó da estrutura
    int v;
    if(isEmpty(p)){
        return 0;
    }else{
        No* aux = p->topo;
        v = aux->item;
        p->topo = aux->prox; // Agora o novo topo deve ser o próximo da variável aux que recebe o valor que será excluído
        free(aux);
    }
    return v;
}


int main() {
    Pilha *p = criaPilha(); // O ponteiro p do tipo Pilha recebe
    pop(p);

    push(p, 20);
    push(p, 30);
    push(p, 40);
    push(p, 50);

    printf("Pilha criada!\n");
    imprimir(p);

    printf("Elemento do topo removido: %d\n", pop(p));
    imprimir(p);

    printf("Elemento do topo removido: %d\n", pop(p));
    imprimir(p);

    libera(p);
    imprimir(p);
    return 0;
}