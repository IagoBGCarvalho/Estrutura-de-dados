#include <stdio.h>
#include <stdlib.h>

// Fila Duplamente encadeada:

// A lista é a estrutura mais flexível, pois não possui restrições quanto a inserção e remoção.

// Duplamente encadeada significa que os elementos são mapeados para frente e para trás (o nó irá possuir ponteiros que apontam para o nó anterior e para o próximo)

typedef struct lista Lista;
typedef struct listano ListaNo;

// A estrutura Lista precisa de dois ponteiros que apontam para o primeiro nó (prim) e para o último (ult), enquanto o PilhaNó precisa do elemento a ser armazenado (elem) e dos ponteiros que apontam para o proximo nó (prox) e para o anterior (ant):

struct lista{
    ListaNo* prim;
    ListaNo* ult;
};

struct listano{
    int elem;
    ListaNo* prox;
    ListaNo* ant;
};

// A partir das estruturas declaradas, é possível realizar as operações da estrutura.

// As operações da lista são:
// Criar a lista
// Criar o no
// Imprimir a lista
// Buscar um elemento da lista
// Verificar se ela esta vazia
// Excluir um elemento
// Liberar a lista

// Criar a lista:
Lista* cria_lista(void){
    // Commo esta operação apenas cria a lista, precisa ser do tipo Lista* para retornar um ponteiro que aponta para a lista iniciada.
    Lista* l = (Lista*)malloc(sizeof(Lista)); // É necessário alocar dinamicamente um espaço do tamanho de uma lista

    // Após o malloc, é necessario atribuir NULL aos ponteiros, visto que a lista não possui nenhum elemento ainda:
    l->prim = NULL;
    l->ult = NULL;
    return l; // Finalmente retorna o ponteiro para a lista criada
}

// Criar o nó:
void cria_no_lista(Lista* l, int valor){
    // O nó recebe a lista criada e o valor a ser armazenado
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo)); // Aloca dinamicamente umn espaco do tamanho de um ListaNo
    novo->elem = valor; // O elemento do nó recebe o item a ser alocado
    novo->prox = l->prim; // Como este algoritmo SEMPRE adiciona os elementos na frente da lista, o proximo elemento do novo elemento sempre será o antigo primeiro elemento
    novo->ant = NULL; // Por ser o primeiro nó da lista, consequentemente, seu anterior sempre será nulo

    if(l->prim != NULL){
        // Este if será acionado a partir da segunda criação de nó, pois, já que o primeiro elemento é diferente de nulo (existem elementos na lista) o anterior ao nó que está como primeiro será o novo elemento
        l->prim->ant = novo;
    }else{
        // Caso l->prim seja nulo (não existem elementos na fila) o último elemento será o novo
        l->ult = novo;
    }
    l->prim = novo; // Finalmente, o novo nó se torna o primeiro da lista
}

// Imprimir a lista:
void imprime_lista(Lista* l){
    ListaNo* p = l->prim; // Ponteiro que aponta para o começo da lista, de onde começará a impressão

    if(p == NULL){
        printf("Lista vazia.\n");
    } else {
        for(p = l->prim; p != NULL; p = p->prox){
            // Lógica do for: p começa o primeiro loop como o primeiro elemento da lista, o loop ocorre enquanto p for diferente de nulo e ao fim de cada loop p irá receber o próximo da lista
            printf("Item = %d\n", p->elem);
        }
    }
}

// Buscar na lista:
ListaNo* busca_lista(Lista* l, int valor){
    // Recebe a lista e o valor ser buscado
    for (ListaNo* p = l->prim; p != NULL; p = p->prox){
        // Mesma lógica de for utilizada para imprimir, mas faz um teste condicional a cada loop para verificar se o elemento de p é igual ao número buscado
        if (p->elem == valor){
            return p; // Caso encontre o valor, retorna o estado atual de p (que é o nó com o valor encontrado)
        }
    }
    return NULL; // Se não encontrar, retorna nada
}

// Verificar se está vazia:
int lista_vazia(Lista* l){
    return (l->prim == NULL); // Retorna 1 caso esteja vazia e 0 caso não esteja
}

void excluir_no_lista(Lista* l, int valor){
    // Recebe a lista e o valor a ser excluido
    ListaNo* p = busca_lista(l, valor); // Cria um ponteiro que recebe o resultado de uma busca utilizando a lista e o valor do parâmetro

    if(p == NULL){
        // Se p retorna NULL, significa que o elemento a ser excluido não está na lista, então retorna nada
        return;
    }

    if (p == l->prim){
        // Caso p seja o primeiro elemento da lista, reposiciona o lugar de primeiro para o segundo (no caso, o próximo de p)
        l->prim = p->prox;
        p->prox->ant = NULL; // Atribui NULL ao própio p
    }else{
        p->ant->prox = p->prox; // O ponteiro prox do elemento anterior ao elemento a ser removido (que está no meio da lista) deve receber o próximo elemento ao que se quer excluir, mantendo o encadeamento.
    }

    if(p == l->ult){
        l->ult = p->ant;
        p->ant->prox = NULL;
    }else{
        p->prox->ant = p->ant;
    }
    free(p);
}

// Liberar a lista:
void libera_lista(Lista* l){
    // Recebe a lista e liberar TODOS os nós da lista e a lista em si
    ListaNo* p = l->prim;

    while (p != NULL){
        ListaNo* t = p->prox; //guarda referência para próximo elemento
        free(p); //libera a memória apontada por p
        p = t; //faz p apontar para o próximo elemento
    }
    free(l); // Por fim, libera a lista por inteiro
    printf("A lista foi liberada.\n");
}

// Pilha:

// Estrutura LIFO (Last In First Out) o último elemento a ser inderido é o último a ser removido.

typedef struct pilha Pilha;
typedef struct pilhano PilhaNo;

// A estrutura Pilha apenas precisa de um ponteiro (topo) que aponta para o elemento que será removido:

struct pilha{
    PilhaNo* topo; // Ponteiro que aponta para o nó do topo da pilha
};

struct pilhano{
    // Estrutura que representa cada nó da pilha
    int item; // Item armazenado
    PilhaNo* prox; // Ponteiro que aponta para o proximo nó
};

// As operações da pilha são:
// stack() - Cria a pilha
// push(item) - Insere um item na pilha
// pop() - Remove o item que está no topo da lista
// peek() - Retorna o item no topo, mas sem remover el
// isEmpty() - Testa se a pilha está vazia
// size() - Retorna o número de itens da pilha

// Cria a pilha:
Pilha* stack(){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha)); // Instancia o a estrutura da pilha

    p->topo = NULL; // Topo instanciado (que é a mesma coisa de criar uma pilha vazia, visto que a estrutura da pilha apenas possui o topo)

    return p; // Retorna o ponteio que aponta para a estrutura criada
}

// Inserir um item na pilha:
void push(Pilha* p, int v){
    PilhaNo* novo = (PilhaNo*)malloc(sizeof(PilhaNo)); // Aloca um espaço dinamicamente com o tamanho de um nó (item e prox)

    novo->item = v; // Atribui o valor do parâmetro ao item do nó
    novo->prox = p->topo; // Como o novo é o novo topo, o próximo dele é o antigo topo
    p->topo = novo; // O topo da pilha recebe o novo elemento
}

// Verifica se a pilha está vazia:
int isEmpty_pilha(Pilha* p){
    if (p->topo == NULL){
        printf("A pilha está vazia!\n");
        return 1; // Está vazia
    }
    return 0; // Está cheia
}

// Remover um item da pilha:
int pop(Pilha* p){
    int v;
    if(isEmpty_pilha(p)){
        return 0;
    }else{
        PilhaNo* aux = p->topo; // Variável auxiliar que receberá o elemento a ser excluído (o topo da pilha)
        v = aux->item;
        p->topo = aux->prox; // Agora o novo topo deve ser o próximo da variável aux que recebe o valor que será excluído
        free(aux);
    }
    return v;
}

// Imprimir a pilha:
void imprimir_pilha(Pilha* p){
    if(isEmpty_pilha(p)){
        return;
    }else{
        for(PilhaNo* q = p->topo; q != NULL; q = q->prox){
        // for: O ponteiro q recebe o endereço do topo da pilha, o for vai continuar enquanto q for diferente de nulo (enquanto ele não for o último elemento) e ao final de cada loop q vai receber o próximo elemento
        printf("Item da pilha: %d\n", q->item); // Imprime o item de cada elemento a cada loop
        }
    }
}

// Liberar a pilha:
void libera_pilha(Pilha* p){
    PilhaNo* aux = p->topo; // Variável auxiliar para receber o topo da estrutura
    while(aux != NULL){
        PilhaNo* t = aux->prox; // Outra variável auxiliar que irá receber o próximo elemento de aux
        free(aux); // Está liberando a memória alocada na localizaçao que aux está apontando (o topo)
        aux = t; // Por fim, aux recebe t, que é o novo topo
    }
    free(p);
    printf("A pilha foi liberada.\n");
}

// Fila:

// Uma fila é uma estrutura FIFO (first in first out), ou seja, os primeiros elementos a entrarem na fila serão os primeirosm a saírem.

typedef struct fila Fila;
typedef struct filano FilaNo;

// A estrutura fila precis do mapeamento do primeiro e do último nó, enquanto o filanó precisa apenas do item e do próximo nó:

struct fila{
    FilaNo* prim;
    FilaNo* ult;
};

struct filano {
    int item;
    FilaNo* prox;
};

// Operações básicas da fila:

// queue(): cria a fila
// enqueue(item): insere um novo elemento na fila
// dequeue(): remove o item do início da fila
// front(): retorna o item do início da fila
// isEmpty(): verifica se a fila está vazia
// size(): retorna o número de elementos da fila

// Cria a fila:
Fila* queue(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->prim = NULL;
    f->ult = NULL;
    return f;
}

// Insere um novo elemento na fila:
void enqueue(Fila* f, int v){
    FilaNo* novo = (FilaNo*)malloc(sizeof(FilaNo));
    novo->item = v;
    novo->prox = NULL; // O novo elemento da fila é sempre o último, e o próximo do último é sempre nulo

    if(f->ult != NULL){
        // Se o último elemento for diferente de nulo, significa que já existem elementos na fila
        f->ult->prox = novo; // Se existe pelo menos um elemento na fila, o próximo do atual último será o novo elemento adicionado
    }else{
        f->prim = novo; // Caso o último da lista seja igual a nulo, significa que ela está vazia, então o primeiro da fila será o novo elemento adicionado
    }
    f->ult = novo;
}

// Remove um elemento da fila:
int dequeue(Fila* f){
    FilaNo* no = f->prim; // Variável para armazenar o nó que será removido (o primeiro da fila)
    int v;

    if(isEmpty_fila(f)){
        return 0;
    }else{
        v = no->item; // A variável que será retornada recebe o valor do item do nó
        f->prim = no->prox; // O primeiro item da fila se torna o próximo do que será excluído
    }

    if(f->prim == NULL){
        // A condição anterior apenas atualiza o prim para nulo, mas não o ult, então é necessário fazer uma condição para atualizar o último quando o primeiro receber nulo
        f->ult = NULL;
    }
    free(no);
    return v;
}

// Imprimir a fila:
void imprimir_fila(Fila* f){
    for(FilaNo* n = f->prim; n != NULL; n = n->prox){
        printf("Item da fila: %d\n", n->item);
    }
}

// Verificar se a lista está vazia:
int isEmpty_fila(Fila* f){
    if(f->prim == NULL){
        printf("Fila vazia.\n");
        return 1;
    }
    return 0;
}

// Liberar a fila:
void libera_fila(Fila* f){
    FilaNo* n = f->prim;
    while(n != NULL){
        FilaNo* aux = n->prox;
        free(n);
        n = aux;
    }
    printf("Fila liberada!\n");
    free(f);
}



int main() {
    // Testes Lista:
    printf("--- Testes da Lista ---\n");
    Lista* l = cria_lista();

    cria_no_lista(l, 23);
    cria_no_lista(l, 45);
    cria_no_lista(l, 56);
    cria_no_lista(l, 78);

    printf("Lista com elementos inseridos \n");
    imprime_lista(l);

    excluir_no_lista(l,78);

    printf("Lista após exclusão do elemento 78 \n");
    imprime_lista(l);

    excluir_no_lista(l, 45);

    printf("Lista após exclusão do elemento 45 \n");
    imprime_lista(l);

    libera_lista(l);
    printf("\n");

    // Testes Pilha:
    printf("--- Testes da Pilha ---\n");
    Pilha *p = stack(); // O ponteiro p do tipo Pilha recebe o retorno da funçãoo que cria a pilha
    pop(p);

    push(p, 20);
    push(p, 30);
    push(p, 40);
    push(p, 50);

    printf("Pilha criada!\n");
    imprimir_pilha(p);

    printf("Elemento do topo removido: %d\n", pop(p));
    imprimir_pilha(p);

    printf("Elemento do topo removido: %d\n", pop(p));
    imprimir_pilha(p);

    libera_pilha(p);
    printf("\n");

    // Testes fila:
    printf("--- Testes da Fila ---\n");

    Fila* f = queue();
    dequeue(f);

    enqueue(f, 20);
    enqueue(f, 30);
    enqueue(f, 40);
    enqueue(f, 50);

    printf("Fila criada!\n");
    imprimir_fila(f);

    printf("Primeiro elemento removido: %d\n", dequeue(f));
    imprimir_fila(f);

    printf("Segundo elemento removido: %d\n", dequeue(f));
    imprimir_fila(f);

    libera_fila(f);
    return 0;
}