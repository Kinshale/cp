#include <cstdio>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

void solve(int t) {
    int N, K;
    cin >> N >> K;

    vector<int> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    sort(C.begin(), C.end());
    std::priority_queue<int> maxHeap;

    for (size_t i = 1; i < C.size(); i++)
        maxHeap.push(C[i] - C[i - 1]);

    int maxDifference = 0;

    for (size_t i = 1; i < K; i++){
        maxDifference += maxHeap.top();
        maxHeap.pop();
    }

    int r = C[N - 1] - C[0] - maxDifference;

    cout << "Case #" << t << ": " << r << "\n";
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
