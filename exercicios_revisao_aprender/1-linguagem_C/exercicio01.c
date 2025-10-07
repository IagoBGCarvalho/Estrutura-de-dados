#include <stdio.h>
#include <stdlib.h>

int Main(){
    typedef struct{
        char descricao[20];
    } TipoPoder;

    typedef struct{
        int id;
        char nome[20];
        float forca;
        TipoPoder poder;
    } TipoLutador;

    void fight(const TipoLutador* timeA, const TipoLutador* timeB, int n, TipoLutador* vencedores){
        TipoLutador = (TipoLutador *) malloc(n*sizeof(TipoLutador));
    }
}