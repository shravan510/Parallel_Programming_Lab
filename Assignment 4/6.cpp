#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    cout << "--- Parallel Series Print ---" << endl;
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            cout << "Series of 2 by thread " << omp_get_thread_num() << ": ";
            for (int i = 1; i <= 10; i++) {
                cout << 2 * i << " ";
            }
            cout << endl;
        }
        #pragma omp section
        {
            cout << "Series of 4 by thread " << omp_get_thread_num() << ": ";
            for (int i = 1; i <= 10; i++) {
                cout << 4 * i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
