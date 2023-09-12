#include <libprg/libprg.h>

int criar(int *vetor,int tamanho)
{
    vetor = (int*) calloc(tamanho,sizeof (int));

    return 0;
}

int insere_nao_ord(int *vetor,int *total,int tamanho,int elemento)
{

    if(tamanho > total){
        vetor[(int) &total] = elemento;
        total++;
    }
    return 0;
}

int insere_ord(int *vetor,int *total,int tamanho,int elemento)
{
    if(total < tamanho){
        for(int i = 0; i < total; i++){
            if(vetor[i] > elemento){
                for(int j = total;j >= i; j--){
                    vetor[j + 1] = vetor[j]
                }
                vetor[i] = elemento;
                break;
            }
        }
    }
    return 0;
}


int busca_linear(int *vetor,int total,int tamanho, int elemento)
{
    for(int i = 0; i < total; i++){
        if(vetor[i] == elemento){
            return 0;
        }
    }
    return 1;
}

int busca_bin_int(int *vetor,int total, int tamanho,int elemento)
{

}

int busca_bin_rec(int *vetor,int total,int tamanho, int elemento)
{

}

int remove_num_ord(int *vetor,int *total,int tamanho,int elemento)
{


    return 0;
}