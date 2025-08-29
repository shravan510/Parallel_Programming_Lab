#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

const int N = 10000000;

int main() {
    vector<double> A(N);
    vector<double> B(N);
    double dot_product_serial = 0.0;
    double dot_product_parallel = 0.0;

    for (int i = 0; i < N; i++) {
        A[i] = i * 1.0;
        B[i] = i * 2.0;
    }

    cout << "--- Serial Vector Dot Product ---" << endl;
    double start_serial = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        dot_product_serial += A[i] * B[i];
    }
    double end_serial = omp_get_wtime();
    cout << "Dot Product: " << dot_product_serial << endl;
    cout << "Time taken: " << end_serial - start_serial << " seconds" << endl;

    cout << "\n--- Parallel Vector Dot Product ---" << endl;
    double start_parallel = omp_get_wtime();
    #pragma omp parallel for reduction(+:dot_product_parallel)
    for (int i = 0; i < N; i++) {
        dot_product_parallel += A[i] * B[i];
    }
    double end_parallel = omp_get_wtime();
    cout << "Dot Product: " << dot_product_parallel << endl;
    cout << "Time taken: " << end_parallel - start_parallel << " seconds" << endl;

    return 0;
}

