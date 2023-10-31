#include <libprg/libprg.h>


int criar(lista_t *lista)
{
    lista->vetor = (int*) calloc(lista->tamanho,sizeof(int));

    if(lista->vetor == NULL){
        return 0;
    }
    return 1;
}


void povoar_nao_ord(lista_t *lista)
{
    srand(time(NULL));
    for(int i = 0;i < lista->tamanho;i++){
        lista->vetor[i] = rand() % 100 + 1;
    }
    lista->total = lista->tamanho;
}

void povoar_ord(lista_t *lista)
{
    srand(time(NULL));
    for (int i = 0; i < lista->tamanho; i++) {
        lista->vetor[i] = rand() % 100 + 1;
        lista->total++;
        for (int j = i; j > 0; j--) {
            if (lista->vetor[j] < lista->vetor[j - 1]) {
                int guarda = lista->vetor[j];
                lista->vetor[j] = lista->vetor[j - 1];
                lista->vetor[j - 1] = guarda;
            } else {
                break;
            }
        }
    }
}

int insere_ord(lista_t *lista, int elemento) {
    if (lista->total < lista->tamanho) {
        for (int i = 0; i < lista->total; i++) {
            if (lista->vetor[i] > elemento) {
                for (int j = lista->total; j >= i; j--) {
                    lista->vetor[j + 1] = lista->vetor[j];
                }
                lista->vetor[i] = elemento;
                lista->total++;
                return 1;  // Elemento inserido com sucesso
            }
        }
    }
    return 0;  // A lista está cheia ou ocorreu um erro
}

int insere_nao_ord(lista_t *lista, int elemento)
{

    if(lista->tamanho > lista->total){
        lista->vetor[lista->total] = elemento;
        lista->total++;
        return 1; // Elemento inserido com sucesso
    }
    return 0; // A lista está cheia ou ocorreu um erro
}


int remove_num_ord(lista_t *lista, int elemento) {
    for (int i = 0; i < lista->total; i++) {
        if (lista->vetor[i] == elemento) {
            for (; i < lista->total - 1; i++) {
                lista->vetor[i] = lista->vetor[i + 1];
            }
            lista->total--;
            return 1; // Elemento removido com sucesso
        }
    }
    return 0; // Elemento não foi removido ou não está na lista
}

int remove_num_nao_ord(lista_t *lista, int elemento)
{
    for(int i = 0;i < lista->total;i++){
        if(lista->vetor[i] == elemento){
            lista->vetor[i] = lista->vetor[lista->total - 1];
            lista->total--;
            return 1; // Elemento removido com sucesso
        }
    }
    return 0; // Elemento não foi removido ou não está na lista
}

int busca_linear(lista_t *lista, int elemento)
{
    for(int i = 0; i < lista->total; i++){
        if(lista->vetor[i] == elemento){
            return i; // Retorna a posição em que o elemento está
        }
    }
    return -1; // Elemento não encontrado
}

int busca_bin_int(lista_t *lista, int elemento) {
    int inicio = 0;
    int fim = lista->total - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista->vetor[meio] == elemento) {
            return meio; // Retorna a posição em que o elemento está
        } else if (lista->vetor[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1; // Elemento não encontrado
}

int busca_bin_rec(lista_t *lista, int inicio, int fim, int elemento) {
    if (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        if (lista->vetor[meio] == elemento) {
            return meio; // Retorna a posição em que o elemento está
        } else if (lista->vetor[meio] > elemento) {
            return busca_bin_rec(lista, inicio, meio - 1, elemento);
        } else {
            return busca_bin_rec(lista, meio + 1, fim, elemento);
        }
    }
    return -1; // Elemento não encontrado
}


int libera_memoria(lista_t *lista)
{
    free(lista->vetor);
    return 1;
}