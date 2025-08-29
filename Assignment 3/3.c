#include<stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(5);
    int arr[22]={5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    int scaler=5;
    double start = omp_get_wtime();
    #pragma omp parallel
        #pragma omp for schedule(dynamic,4)
        for(int i=0;i<22;i++){
            arr[i]+=scaler;
            printf(" By Thread %d Arr[%d] = %d \n",omp_get_thread_num(),i,arr[i]);
        }
    double end = omp_get_wtime();
    printf("Static Time: %f seconds\n", end - start);
    return 0;
    }
    