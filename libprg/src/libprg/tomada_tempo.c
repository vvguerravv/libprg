#include <libprg/libprg.h>

void inicio(struct timeval *inicio)
{
    gettimeofday(inicio, 0);
}

double fim_relogio_parede(struct timeval *inicio)
{
    struct timeval fim;

    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio->tv_sec;
    long mseg = fim.tv_usec - inicio->tv_usec;
    double tempo_total = seg + mseg * 1e-6;
    return tempo_total;
}

double fim_CPU(clock_t inicio)
{
    clock_t fim = clock();
    return ((double) (fim - inicio)) / CLOCKS_PER_SEC;
}