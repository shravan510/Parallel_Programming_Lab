#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int sum_squares = 0;
    cout << "--- Squares of Thread IDs ---" << endl;
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        int square = id * id;
        cout << "Thread ID: " << id << ", Square: " << square << endl;
        #pragma omp atomic
        sum_squares += square;
    }
    cout << "\n--- Final Sum of Squares ---" << endl;
    cout << "Total Sum: " << sum_squares << endl;
    return 0;
}

