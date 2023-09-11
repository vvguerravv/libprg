#include <libprg/libprg.h>

int criar(int *vetor,int tamanho)
{
    vetor = (int*) calloc(tamanho,sizeof (int));

    return 0;
}

int insere_nao_ord(int *vetor,int *total,int tamanho,int elemento)
{

    if(tamanho >= total){
        vetor[(int) &total] = elemento;
    }

    total++;

    return 0;
}