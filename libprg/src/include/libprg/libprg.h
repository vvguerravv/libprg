#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *
 * @param vetor
 * @param total
 * @param elemento
 * @return 0 se ok e 1 se não ok
 */

#define NUM_MAX 1000

//Irá criar um vetor povoado com número aleatórios que o usuário irá escolher
int criar(int *vetor,int tamanho);

//Irá inserir número em uma lista ordenada
int insere_ord(int *vetor,int *total,int tamanho,int elemento);

//Irá inserir um número em uma lista não ordenada
int insere_nao_ord(int *vetor,int *total,int tamanho,int elemento);

//Irá remover um número de uma lista ordenada
int remove_num_ord(int *vetor,int *total,int tamanho,int elemento);

//Irá remover um número de uma lista não ordenada
int remove_num_nao_ord(int *vetor,int *total,int tamanho,int elemento);

//Irá fazer uma busca linear pelo vetor
int busca_linear(int *vetor,int total,int tamanho, int elemento);

//Irá fazer uma busca binaria de forma interativa pelo vetor
int busca_bin_int(int *vetor,int total, int tamanho,int elemento);

//Irá fazer uma busca binaria de forma recursiva pelo vetor
int busca_bin_rec(int *vetor,int total,int tamanho, int elemento);


//Irá liberar a memório alocado pelo vetor
int libera_memoria(int *vetor,int tamanho);



#endif
