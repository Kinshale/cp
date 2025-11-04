#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long> &D) {
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 0; i < M; i++) adj[X[i]].push_back({Y[i], P[i]});

    for (int i = 0; i < N; i++) D[i] = LLONG_MAX;

    vector<bool> processed(N, false);
    priority_queue<pair<long long, int>> q;
    D[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        int x = q.top().second;
        q.pop();

        if (processed[x]) continue;
        processed[x] = true;

        for (auto u : adj[x]) {
            int y = u.first;
            int weight = u.second;
            if (D[y] > D[x] + weight) {
                D[y] = D[x] + weight;
                q.push({-D[y], y});  // Using negative for min-heap behavior
            }
        }
    }

    for (int i = 0; i < N; i++)
        if (D[i] == LLONG_MAX) D[i] = -1;
}
