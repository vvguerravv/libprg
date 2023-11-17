#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <sys/time.h>
#include <limits.h>
#include <stdint.h>

// =========================== TOMADA DE TEMPO =========================== //
void inicio_relogio_parede(struct timeval *inicio);
double fim_relogio_parede(struct timeval *inicio);
void relogio_CPU();


// =========================== LISTA =========================== //

//Irá criar um vetor povoado com número aleatórios que o usuário irá escolher
typedef struct {
    int *vetor;
    int tamanho;
    int total;
    int inicio;
    int pos;
}lista_t;

//Irá criar um vetor de tamanho n, alocado de forma dinâmica
int criar(lista_t *lista);

//Irá povoar o vetor criado se for não ordenado
void povoar_nao_ord(lista_t *lista);

//Irá povoar o vetor criado se for ordenado
void povoar_ord(lista_t *lista);

//Irá inserir número em uma lista ordenada
int insere_ord(lista_t *lista, int elemento);

//Irá inserir um número em uma lista não ordenada
int insere_nao_ord(lista_t *lista, int elemento);

//Irá remover um número de uma lista ordenada
int remove_num_ord(lista_t *lista, int elemento);

//Irá remover um número de uma lista não ordenada
int remove_num_nao_ord(lista_t *lista, int elemento);

//Irá fazer uma busca linear pelo vetor
int busca_linear(lista_t *lista, int elemento);

//Irá fazer uma busca binaria de forma interativa pelo vetor e retorna a posição do elemento no vetor
int busca_bin_int(lista_t *lista, int elemento);

//Irá fazer uma busca binaria de forma recursiva pelo vetor e retorna a posição do elemento no vetor
int busca_bin_rec(lista_t *lista, int inicio, int fim, int elemento);

//Irá liberar a memório alocado pelo vetor
int libera_memoria(lista_t *lista);

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

//Inicio = (start + 1) % n

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
    int element;
    struct no * next;
}no_t;

typedef struct {
    no_t *start;
    int size;
}ChainedList_t;

typedef struct {
    no_t *high;
    int size;
}Stackist_t;

void addList(ChainedList_t *queue, no_t **node, int value);
int removeList(ChainedList_t *queue, no_t **node);
int searchList(no_t **node, int element);

void addStack(Stackist_t *stack, no_t **node, int element);
int removeStack(Stackist_t *stack, no_t **node);
int searchStack(no_t **node, int element);

void addCircle(no_t **node, bool op, int value);
int removeCircle(no_t **node, int value);
int searchCircle(no_t **node,int value);

void printNo(no_t *node);


// -------------- DUPLA -------------- //
typedef struct nod{
    int elemento;
    struct nod_t* proximo;
    struct nod_t* anterior;
}nod_t;



// =================================== ORDENAÇÃO =================================== //
typedef struct {
    int *vet;
    int tamanho;
}ord_t;

int criar_vet(ord_t *ord);
int povoar(ord_t *ord);
void bubble(ord_t *ord,bool crescente);
void insert(ord_t *ord);
void selection(ord_t *ord,bool crescente);
void nosso(ord_t *ord);
void merge_sort(ord_t *ord, int left, int right);
void merge(ord_t *ord, int left, int mid, int right);
void imprimi(ord_t *ord);



#endif