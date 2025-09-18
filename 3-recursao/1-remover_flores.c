#include <stdio.h>

void esvaziarVaso(int flores) {
    if (flores <= 0) { // Caso base - condição de parada
        return;
    }

    printf("%d\n", flores);
    esvaziarVaso(flores - 1); // Chamando a si mesma e alterando o seu estado
}

int main() {
    // Recursividade se trata de uma função que chama a si mesma diversas vezes até resolver um determinado problema. 
    // Divide-se o problema em um conjunto de problemas menores
    // Uma função recursiva precisa de um caso base, ou seja, onde ela vai parar, 
    // um algoritmo recursivo que modifica o seu estado em direção ao caso base e, 
    // por fim, deve chamar a si mesma

    int flores = 10;

    esvaziarVaso(flores);
    return 0;
}