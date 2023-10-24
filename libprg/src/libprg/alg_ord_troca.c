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