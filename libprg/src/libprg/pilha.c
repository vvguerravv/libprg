#include <libprg/libprg.h>

int push(pilha_t *pilha, int elemento)
{
    if(pilha->tamanho == pilha->total){
        return 1;
    }
    pilha->vetor[pilha->topo] = elemento;
    pilha->topo++;
}

int pop(pilha_t *pilha)
{
    if(pilha->vetor == NULL){
        return 1;
    }
    int num = pilha->vetor[pilha->topo];
    pilha->topo--;
    return num;
}