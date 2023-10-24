#include <libprg/libprg.h>

void inicio_relogio_parede(struct timeval inicio)
{
    gettimeofday(&inicio, 0);
}

double fim_relogio_parede(struct timeval inicio)
{
    struct timeval fim;

    gettimeofday(&fim, 0);

    long seg = fim.tv_sec - inicio.tv_sec;
    long mseg = fim.tv_usec - inicio.tv_usec;
    double tempo_total = seg + mseg * 1e-6;
    return tempo_total;
}

void relogio_CPU()
{
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    while (1) {
        if (getchar())
            break;
    }

    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
}



