#include <iostream>
#include <omp.h>

using namespace std;

const int N = 1000000;

int main() {
    int counter_no_sync = 0;
    cout << "--- Counter without synchronization ---" << endl;
    double start_no_sync = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        counter_no_sync++;
    }
    double end_no_sync = omp_get_wtime();
    cout << "Final counter value: " << counter_no_sync << endl;
    cout << "Time taken: " << end_no_sync - start_no_sync << " seconds" << endl;

    int counter_critical = 0;
    cout << "\n--- Counter with #pragma omp critical ---" << endl;
    double start_critical = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp critical
        counter_critical++;
    }
    double end_critical = omp_get_wtime();
    cout << "Final counter value: " << counter_critical << endl;
    cout << "Time taken: " << end_critical - start_critical << " seconds" << endl;

    return 0;
}

