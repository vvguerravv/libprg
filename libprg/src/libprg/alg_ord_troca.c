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

void merge(ord_t *ord, int left, int mid, int right){
    int *aux = (int *) malloc(sizeof(right - left + 1));
    int i = left;
    int j = mid + 1;
    int k = 0;
    while((i <= mid) && (j <= right)){
        if(ord->vet[i] <= ord->vet[j]){
            aux[k] = ord->vet[i];
            i++;
        }else{
            aux[k] = ord->vet[j];
            j++;
        }
        k++;
    }
    while(i <= mid){
        aux[k] = ord->vet[i];
        i++; k++;
    }
    while(j <= right){
        aux[k] = ord->vet[j];
        j++; k++;
    }
    for(i = left; i <= right; i++){
        ord->vet[i] = aux[i - left];
    }
    free(aux);
}

void merge_sort(ord_t *ord, int left, int right){
    int mid;
    if(left < right){
        mid = left + (right - left) / 2;
        merge_sort(ord, left, mid);
        merge_sort(ord, mid + 1, right);
        merge(ord, left, mid, right);
    }
}

void troca_pos(ord_t *ord, int i, int j)
{
   ord->vet[i] = ord->vet[j];
}

int particiona(ord_t *ord, int start, int end)
{
    int pivo = ord->vet[end];
    int i = start - 1;
    for(int j = start; j < end ; j++){
        if(ord->vet[j] <= pivo){
            i++;
            troca_pos(ord, i, j);
        }
    }
    i++;
    troca_pos(ord, i, end);
    return i;
}

void quick_sort(ord_t *ord, int start, int end)
{
    int p;
    if(start < end){
        p = particiona(ord, start, end);
        quick_sort(ord, start, p - 1);
        quick_sort(ord, p + 1, end);
    }
}
