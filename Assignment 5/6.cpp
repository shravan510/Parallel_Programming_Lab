#include <iostream>
#include <omp.h>

using namespace std;

const int N = 10;

int main() {
    long long factorial_critical = 1;
    cout << "--- Factorial with #pragma omp critical ---" << endl;
    double start_critical = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 1; i <= N; i++) {
        #pragma omp critical
        factorial_critical *= i;
    }
    double end_critical = omp_get_wtime();
    cout << "Factorial of " << N << " is: " << factorial_critical << endl;
    cout << "Time taken: " << end_critical - start_critical << " seconds" << endl;

    long long factorial_reduction = 1;
    cout << "\n--- Factorial with #pragma omp reduction ---" << endl;
    double start_reduction = omp_get_wtime();
    #pragma omp parallel for reduction(*:factorial_reduction)
    for (int i = 1; i <= N; i++) {
        factorial_reduction *= i;
    }
    double end_reduction = omp_get_wtime();
    cout << "Factorial of " << N << " is: " << factorial_reduction << endl;
    cout << "Time taken: " << end_reduction - start_reduction << " seconds" << endl;

    return 0;
}

