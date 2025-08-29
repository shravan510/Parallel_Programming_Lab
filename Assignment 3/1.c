#include<stdio.h>
#include <omp.h>

int main() {

    printf("Sequential Code\n");
    for(int i=0;i<5;i++){
        printf("Helo world %d from thread %d \n",i,omp_get_thread_num());
    }

    printf("\n\nParallel code\n");
    #pragma omp parallel for
    for(int i=0;i<5;i++){
        printf("Helo world %d from thread %d \n",i,omp_get_thread_num());
    }
    
    return 0;
}
