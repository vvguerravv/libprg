#include <libprg/libprg.h>

int enqueue(fila_t *fila , int elemento)
{
    if(fila->tamanho == fila->total){
        return 1;
    }
    fila->vetor[fila->fim] = elemento;
    fila->fim = (fila->fim + 1)% fila ->tamanho;
    fila->total++;

    return 0;
}

int dequeue(fila_t *fila)
{
    if(fila->vetor)
    fila->inicio = (fila->inicio + 1) % fila ->tamanho;
    fila->total--;
    return fila->vetor[fila->inicio];
}

int head(fila_t *fila)
{
    return fila->vetor[fila->inicio];
}

int tail(fila_t *fila)
{
    return fila->vetor[fila->fim];
}

int size(fila_t *fila)
{
    return fila->total;
}

int empty(fila_t *fila)
{
    if(fila->total == 0){
        return 0;
    }
    return 1;
}

int full(fila_t *fila)
{
    if(fila->total == fila->tamanho){
        return 0;
    }
    return 1;
}

