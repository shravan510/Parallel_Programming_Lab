#include<stdio.h>
#include <omp.h>

int main() {
    omp_set_num_threads(5);
    int a[5]={1,2,3,4,5};
    int b[5]={6,7,8,9,10};
    int sum[5];

    #pragma omp parallel for
    for(int i=0;i<5;i++){
        sum[i]=a[i]+b[i];
        printf("Sum=%d by thread %d\n",sum[i],omp_get_thread_num());
    }
    
    for(int i=0;i<5;i++){
        printf("%d ",sum[i]);
    }
    printf("\n");
    return 0;
}
