#include <libprg/libprg.h>

int criar_vet(ord_t *ord)
{
    ord->vet = (int*) calloc(ord->tamanho,sizeof(int));

    if(ord->vet == NULL){
        printf("Não foi possível criar o vetor\n");
        exit(EXIT_FAILURE);
    }

    return 1;
}

int povoar(ord_t *ord)
{
    srand(1);
    for(int i = 0;i < ord->tamanho;i++){
        ord->vet[i] = rand() % 100 + 1;
    }
    return 0;
}

void imprimi(ord_t *ord)
{
    for(int i = 0; i < ord->tamanho;i++){
        printf("%d ",ord->vet[i]);
    }
    printf("\n");
}

void nosso(ord_t *ord)
{
    for(int i = 0;i < ord->tamanho;i++){
        int menor = ord->vet[i];
        int pos = i;
        for(int j = i + 1;j < ord->tamanho; j++){
            if(menor > ord->vet[j]){
                menor = ord->vet[j];
                pos = j;
            }
        }
        int guarda = ord->vet[i];
        ord->vet[i] = menor;
        ord->vet[pos] = guarda;
    }
}

void bubble(ord_t *ord, bool crescente)
{
    for(int i = 0; i < ord->tamanho; i++){
        for (int j = ord->tamanho - 1; j > 0;j--){
            if((ord->vet[j] < ord->vet[j - 1] && crescente == true) ||(ord->vet[j] > ord->vet[j - 1] && crescente == false) ){
                int aux = ord->vet[j];
                ord->vet[j] = ord->vet[j - 1];
                ord->vet[ j - 1] = aux;
            }
        }
    }
}

void insert(ord_t *ord)
{
    for(int i = 0; i < ord->tamanho; i++){
        int chave = ord->vet[i];
        int j = i - 1;
        while(j >= 0 && ord->vet[j] > chave){
            ord->vet[j + 1] = ord->vet[j];
            j = j - 1;
        }
        ord->vet[j + 1] = chave;
    }
}

void selection(ord_t *ord, bool crescente)
{
    for(int i = 0; i < ord->tamanho; i++){
        int guarda = i;
        for(int j = i+1; j < ord->tamanho;j++){
            if((ord->vet[j] < ord->vet[guarda] && crescente == true) || (ord->vet[j] > ord->vet[guarda] && crescente == false) ) {
                guarda = j;
            }
        }
        if(i != guarda){
            int aux = ord->vet[i];
            ord->vet[i] = ord->vet[guarda];
            ord->vet[guarda] = aux;
        }
    }
}

void merge_sort(ord_t *ord,int esquerda, int direita)
{
    if(esquerda < direita){
        int meio = esquerda + (direita - esquerda)/2;
        merge_sort(ord,esquerda,meio);
        merge_sort(ord,meio + 1,direita);
        merge(ord,esquerda,meio,direita);
    }
}

void merge(ord_t *ord,int meio,int esquerda, int direita)
{
    int *aux = (int*) calloc(direita - esquerda + 1,sizeof(int));
    int i = esquerda; int j = meio + 1 ; int k = 0;

    while(i <= meio && j <= direita){
        if(ord->vet[i] <= ord->vet[j]){
            aux[k] = ord->vet[i];
            i++;
        } else{
            aux[k] = ord->vet[j];
            j++;
        }
    }

    while(i <= meio){
        aux[k] = ord->vet[i];
        i++;k++;
    }

    while(j <= direita){
        aux[k] = ord->vet[j];
        j++;k++;
    }

    for(i = esquerda; i < direita;i++){
        ord->vet[i] = aux[i - esquerda];
    }

    free(aux);
}