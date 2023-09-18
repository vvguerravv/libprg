#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_MAX 1000

// =========================== LISTA =========================== //


//Irá criar um vetor povoado com número aleatórios que o usuário irá escolher
int criar(int *vetor,int tamanho);

//Irá povoar o vetor criado
int povoar(int *vetor,int tamanho);

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

// =================================== FILA ===================================//

typedef struct{
    int *vetor;
    int total;
    int inicio;
    int fim;
    int tamanho;
}fila_t;


//Irá incluir um elemento na lista
int enqueue(fila_t *fila , int elemento);

//Irá remover um elemento da fila
int dequeue(fila_t *fila);

//Irá retornar o elemento que está no início da fila
int head(fila_t *fila);

//Irá retornar o elemento que esta no fim da fila
int tail(fila_t *fila);

//Irá retornar o total de elementos da fila
int size(fila_t *fila);

//Irá indicar se a fila está vazia ou não
int empty(fila_t *fila);

//Irá indicar se a fila está cheia ou não
int full(fila_t *fila);

//Inicio = (inicio + 1) % n

#endif
