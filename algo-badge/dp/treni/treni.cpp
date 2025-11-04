#include <algorithm>
#include <vector>

using namespace std;

int tempo_massimo(int N, int a[], int b[]) {
    vector<int> super(N, 0);
    vector<int> hyper(N, 0);

    super[0] = a[0];
    hyper[0] = b[0];

    super[1] = max(super[0], hyper[0]) + a[1];
    hyper[1] = b[1];

    for (int i = 2; i < N; i++) {
        super[i] = max(super[i - 1], hyper[i - 1]) + a[i];
        hyper[i] = max(super[i - 2], hyper[i - 2]) + b[i];
    }

    return max(super[N - 1], hyper[N - 1]);
}
