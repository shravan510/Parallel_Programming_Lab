#include <iostream>
#include <omp.h>

using namespace std;

const int N = 20;

int main() {
    int final_sum = 0;
    cout << "--- Lastprivate Clause Example ---" << endl;
    #pragma omp parallel for lastprivate(final_sum)
    for (int i = 1; i <= N; i++) {
        final_sum += i;
    }
    cout << "Final sum: " << final_sum << endl;
    return 0;
}
