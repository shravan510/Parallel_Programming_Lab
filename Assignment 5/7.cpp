#include <iostream>
#include <omp.h>

using namespace std;

const int N = 1000000;

int main() {
    double sum_squares = 0.0;

    cout << "--- Sum of Squares of First " << N << " Numbers ---" << endl;
    double start_time = omp_get_wtime();

    #pragma omp parallel for reduction(+:sum_squares)
    for (int i = 1; i <= N; i++) {
        sum_squares += (double)i * i;
    }

    double end_time = omp_get_wtime();
    cout << "Sum of squares: " << sum_squares << endl;
    cout << "Time taken: " << end_time - start_time << " seconds" << endl;

    return 0;
}

