#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

const int N = 1000000;

int main() {
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1;
    }

    long long sum_atomic = 0;
    cout << "--- Sum with #pragma omp atomic ---" << endl;
    double start_atomic = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp atomic
        sum_atomic += arr[i];
    }
    double end_atomic = omp_get_wtime();
    cout << "Final sum: " << sum_atomic << endl;
    cout << "Time taken: " << end_atomic - start_atomic << " seconds" << endl;

    long long sum_critical = 0;
    cout << "\n--- Sum with #pragma omp critical ---" << endl;
    double start_critical = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp critical
        sum_critical += arr[i];
    }
    double end_critical = omp_get_wtime();
    cout << "Final sum: " << sum_critical << endl;
    cout << "Time taken: " << end_critical - start_critical << " seconds" << endl;

    return 0;
}

