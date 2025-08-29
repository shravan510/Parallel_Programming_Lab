#include <iostream>
#include <omp.h>

using namespace std;

const long long N = 100000000;

int main() {
    double sum = 0.0;
    double pi = 0.0;
    double step = 1.0 / N;

    cout << "--- Pi Calculation using OpenMP Reduction ---" << endl;
    double start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum)
    for (long long i = 0; i < N; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    pi = sum * step;

    double end_time = omp_get_wtime();
    cout.precision(17);
    cout << "Pi value: " << pi << endl;
    cout << "Time taken: " << end_time - start_time << " seconds" << endl;

    return 0;
}
