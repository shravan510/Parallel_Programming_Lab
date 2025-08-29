#include <iostream>
#include <omp.h>

using namespace std;

int main() {
    int Aryabhatta = 10;
    cout << "--- Multiplication with private 'Aryabhatta' ---" << endl;
    #pragma omp parallel firstprivate(Aryabhatta)
    {
        int id = omp_get_thread_num();
        int result = id * Aryabhatta;
        cout << "Thread ID: " << id << ", Result: " << result << endl;
    }
    return 0;
}
