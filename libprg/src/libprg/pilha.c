#include <libprg/libprg.h>

int vet_pilha(pilha_t *pilha)
{
    pilha->vetor = (int*) calloc(pilha->tamanho,sizeof (int));
    pilha->topo = -1;
    if(pilha->vetor == NULL){
        return 0;
    }
    return 1;
}

int push(pilha_t *pilha, int elemento)
{
    if(pilha->tamanho == pilha->topo + 1){
        return 0;
    }
    pilha->vetor[++pilha->topo] = elemento;
    return 1;
}

int pop(pilha_t *pilha)
{
    if(pilha->vetor == NULL || pilha->topo == -1){
        return 1;
    }
    int num = pilha->vetor[pilha->topo];
    pilha->topo--;
    return num;
}

int size_p(pilha_t pilha)
{
    return pilha.topo + 1;
}

int empty_p(pilha_t pilha)
{
    if(pilha.topo >= 0){
        return 1;
    }
    return 0;
}