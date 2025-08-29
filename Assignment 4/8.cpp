#include <iostream>
#include <vector>
#include <numeric>
#include <omp.h>

using namespace std;

const int N = 10000000;

int main() {
    vector<int> data(N);
    for (int i = 0; i < N; i++) {
        data[i] = 1;
    }

    long long sum_serial = 0;
    cout << "--- Serial Summation ---" << endl;
    double start_serial = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        sum_serial += data[i];
    }
    double end_serial = omp_get_wtime();
    cout << "Sum: " << sum_serial << endl;
    cout << "Time: " << end_serial - start_serial << " seconds" << endl;

    long long sum_parallel = 0;
    cout << "\n--- Parallel Summation with Reduction ---" << endl;
    double start_parallel = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum_parallel)
    for (int i = 0; i < N; i++) {
        sum_parallel += data[i];
    }
    double end_parallel = omp_get_wtime();
    cout << "Sum: " << sum_parallel << endl;
    cout << "Time: " << end_parallel - start_parallel << " seconds" << endl;

    return 0;
}
