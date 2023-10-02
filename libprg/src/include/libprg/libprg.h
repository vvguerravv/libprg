#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define NUM_MAX 1000

// =========================== LISTA =========================== //


//Irá criar um vetor povoado com número aleatórios que o usuário irá escolher
int criar(int *vetor,int tamanho);

//Irá povoar o vetor criado se for não ordenado
int povoar_nao_ord(int *vetor,int *total,int tamanho);

//Irá povoar o vetor criado se for ordenado
int povoar_ord(int *vetor,int *total,int tamanho);

//Irá inserir número em uma lista ordenada
int insere_ord(int *vetor,int *total,int tamanho,int elemento);

//Irá inserir um número em uma lista não ordenada
int insere_nao_ord(int *vetor,int *total,int tamanho,int elemento);

//Irá remover um número de uma lista ordenada
int remove_num_ord(int *vetor,int *total,int elemento);

//Irá remover um número de uma lista não ordenada
int remove_num_nao_ord(int *vetor,int *total,int elemento);

//Irá fazer uma busca linear pelo vetor
int busca_linear(int *vetor,int total, int elemento);

//Irá fazer uma busca binaria de forma interativa pelo vetor e retorna a posição do elemento no vetor
int busca_bin_int(int *vetor,int total,int elemento);

//Irá fazer uma busca binaria de forma recursiva pelo vetor e retorna a posição do elemento no vetor
int busca_bin_rec(int *vetor,int inicio,int fim, int elemento);

//Irá liberar a memório alocado pelo vetor
int libera_memoria(int *vetor,int tamanho);

// =================================== FILA =================================== //

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

// =================================== PILHA =================================== //

typedef struct{
    int *vetor;
    int topo;
    int tamanho;
}pilha_t;

//Irá criar um vetor para a pilha
int vet_pilha(pilha_t *pilha);

//Irá adicionar um elemento ao topo da pilha
int push(pilha_t *pilha, int elemento);

//Irá remover o elemento que está no topo da pilha
int pop(pilha_t *pilha);

//Irá retornar o total de elementos que tem na pilha
int size_p(pilha_t pilha);

//irá indicar se a pilha está vazia ou não
int empty_p(pilha_t pilha);


// =================================== LISTA EM ALOCAÇÃO ENCADEADA=================================== //

                             // -------------- SIMPLES -------------- //
typedef struct no{
    int elemento;
    struct no_t* proximo;
}no_t;

no_t* create(int elemento);
no_t* buscar_ordenada (no_t* inicio, int elemento);
no_t* buscar_nao_ord(no_t* inicio, int elemento);
no_t* inserir_ordenada(no_t* inicio, int elemento);
no_t* inserir_nao_ord(no_t* inicio, int elemento);
void destruir(no_t* inicio);

                          // -------------- DUPLA -------------- //
typedef struct nod{
    int elemento;
    struct nod_t* proximo;
    struct nod_t* anterior;
}nod_t;

nod_t* create_dup(int elemento);
nod_t* buscar_ord_dup(nod_t* inicio, int elemento);
nod_t* busca_nao_ord_dup(nod_t* inicio, int elemento);
nod_t* inserir_ord_sup(nod_t* inicio, int elemento);
nod_t* inserir_nao_ord_sup(nod_t* inicio, int elemento);
void destruir_dup(nod_t* inicio);


#endif
