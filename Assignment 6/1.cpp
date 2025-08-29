#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

const int N = 256;

int main() {
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    vector<vector<int>> C(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }

    cout << "--- Serial Matrix Multiplication ---" << endl;
    double start_serial = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_serial = omp_get_wtime();
    cout << "Time taken: " << end_serial - start_serial << " seconds" << endl;

    cout << "\n--- Parallel Matrix Multiplication ---" << endl;
    C = vector<vector<int>>(N, vector<int>(N, 0));
    double start_parallel = omp_get_wtime();
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_parallel = omp_get_wtime();
    cout << "Time taken: " << end_parallel - start_parallel << " seconds" << endl;

    return 0;
}

