#include <iostream>
#include <vector>
#include <numeric>
#include <omp.h>

using namespace std;

const int N = 1000000;

int main() {
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        data[i] = i + 1;
    }

    long long total_sum_no_sync = 0;
    cout << "--- Unsynchronized Sum ---" << endl;
    double start_no_sync = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        total_sum_no_sync += data[i];
    }
    double end_no_sync = omp_get_wtime();
    cout << "Sum: " << total_sum_no_sync << endl;
    cout << "Time: " << end_no_sync - start_no_sync << " seconds" << endl;

    long long total_sum_critical = 0;
    cout << "\n--- Sum with critical ---" << endl;
    double start_critical = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp critical
        total_sum_critical += data[i];
    }
    double end_critical = omp_get_wtime();
    cout << "Sum: " << total_sum_critical << endl;
    cout << "Time: " << end_critical - start_critical << " seconds" << endl;

    long long total_sum_atomic = 0;
    cout << "\n--- Sum with atomic ---" << endl;
    double start_atomic = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp atomic
        total_sum_atomic += data[i];
    }
    double end_atomic = omp_get_wtime();
    cout << "Sum: " << total_sum_atomic << endl;
    cout << "Time: " << end_atomic - start_atomic << " seconds" << endl;

    return 0;
}

