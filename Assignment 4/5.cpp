#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

const int N = 512;

void initialize_matrices(vector<vector<int>>& A, vector<vector<int>>& B) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }
    }
}

int main() {
    vector<vector<int>> A(N, vector<int>(N));
    vector<vector<int>> B(N, vector<int>(N));
    vector<vector<int>> C(N, vector<int>(N, 0));

    initialize_matrices(A, B);

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

    C = vector<vector<int>>(N, vector<int>(N, 0));
    cout << "\n--- Static Scheduling ---" << endl;
    double start_static = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_static = omp_get_wtime();
    cout << "Time taken: " << end_static - start_static << " seconds" << endl;

    C = vector<vector<int>>(N, vector<int>(N, 0));
    cout << "\n--- Dynamic Scheduling ---" << endl;
    double start_dynamic = omp_get_wtime();
    #pragma omp parallel for schedule(dynamic)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    double end_dynamic = omp_get_wtime();
    cout << "Time taken: " << end_dynamic - start_dynamic << " seconds" << endl;

    return 0;
}
