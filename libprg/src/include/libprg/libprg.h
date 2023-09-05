#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H



typedef struct {
    double value;
    int error;
} result_t;

typedef enum { SUM, SUB } operation_t;



result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

/**
 *
 * @param vetor
 * @param total
 * @param elemento
 * @return 0 se ok e 1 se não ok
 */
int insere_num(int *vetor,int *total,int tam_vetor,int elemento);
int remove_num(int *vetor,int *total,int elemento);
int busca_linear(int *vetor,int elemento);
int busca_bin_int(int *vetor,int elemento);
int busca_bin_rec(int *vetor,int elemento);

#endif
