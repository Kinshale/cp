#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

void solve(int t) {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> Z(A), X(B), Y(B);

    for (int i = 0; i < A; i++) cin >> Z[i];

    for (int i = 0; i < B; i++) cin >> X[i] >> Y[i];

    int idx = -1;  // memorizza qui l'indice della lampadina
    int num = -1;  // memorizza qui il numero di interruttori

    vector<int> G[N];
    for (int i = 0; i < B; i++) {
        G[X[i]].push_back(Y[i]);
        G[Y[i]].push_back(X[i]);
    }

    queue<int> q;
    vector<bool> visited(N, false);
    vector<int> distance(N, -1);

    for (auto s : Z) {
        visited[s] = true;
        distance[s] = 1;
        q.push(s);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto u : G[x]) {
            if (visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[x] + 1;
            q.push(u);
        }
    }

    for (int i = 0; i < N; i++)
        if (distance[i] > num) {
            num = distance[i];
            idx = i;
        }

    cout << "Case #" << t << ": " << idx << " " << num << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        solve(t);
    }

    return 0;
}
