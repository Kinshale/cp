#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<int> segmentTree;
int n;

void inizia(int N, vector<int> A) {
    int size = 1;
    while (size <= N) size <<= 1;

    segmentTree.resize(size << 1);
    n = size;

    for (int i = 0; i < N; i++) segmentTree[i + n] = A[i];

    for (int i = n - 1; i >= 1; i--) segmentTree[i] = max(segmentTree[i << 1], segmentTree[(i << 1) | 1]);
}

void aggiorna(int P, int X) {
    P += n;
    segmentTree[P] = X;

    for (; P > 1; P >>= 1) segmentTree[P >> 1] = max(segmentTree[P], segmentTree[P ^ 1]);  // ^ gets the sibling
}

int massimo(int L, int R) {
    int l = L + n;
    int r = R + n;

    int res = INT_MIN;
    while (l <= r) {
        if (l & 1) {
            res = max(res, segmentTree[l]);
            l++;
        }
        if (!(r & 1)) {
            res = max(res, segmentTree[r]);
            r--;
        }
        l >>= 1;
        r >>= 1;
    }

    return res;
}

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int &x : A) cin >> x;

    inizia(N, A);

    for (int i = 0; i < Q; i++) {
        char t;
        cin >> t;

        if (t == 'U') {
            int P, V;
            cin >> P >> V;
            aggiorna(P, V);
        }
        if (t == 'Q') {
            int L, R;
            cin >> L >> R;
            cout << massimo(L, R) << "\n";
        }
    }
}
