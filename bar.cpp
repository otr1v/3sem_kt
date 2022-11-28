#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <cstring>
struct teplo
{
    int M;
    double T;
    double h;
    double Tay;
    double* old_data;
    double* new_data;
};
void* func(void* str)
{
    teplo* str = (teplo*) str;
    for (int i = 0; i < )
}
int main()
{
    const int Nthreads = 2;
    teplo str[Nthreads];
    int M = 10;
    double* Uold = (double*) calloc(M, sizeof(double));
    double* Unew = (double*) calloc(M, sizeof(double));
    Uold[M - 1] = 1;
    for (int i = 1; i < 10; i++)
    {
        Unew[M - 1] = 1;
        Unew[0] = 0;
        for(int index = 1; index < M - 1; index++)
        {
            Unew[index] = Uold[index] + 0.3 * (Uold[index + 1] - 2 * Uold[index] + Uold[index - 1]);
        }

        memcpy(Uold, Unew, sizeof(double) * M);
        
    }
    for (int i = 0; i < Nthreads; i++)
    {
        str[i].M = (int)M/Nthreads;
        str[i].T = 100;
        str[i].h = (double) 1/ str[i].M;
        str[i].Tay = 0.3 * str[i].h * str[i].h;
        str[i].old_data = str[i].old_data + (i * Nthreads);
        str[i].old_data = Uold + (i* Nthreads);
        str[i].old_data = str[i].old_data + (i * Nthreads);
        str[i].old_data = Uold + (i* Nthreads);
    }
    // teplo[]= 11;
    // double T = 100;
    // double P = 2;
    // double h = (double)1 / M;
    // double Tay = 0.3 * h * h;
    // int N = (int) (T / Tay);
    // for (int i = 0; i < (M - 1) ; i++)
    // {
    //     Uold[i] = 0;
    // }
    
    for(int i = 0; i < M; i++)
    {
        printf("%lg\n", Uold[i]);
    }
    return 0;
}