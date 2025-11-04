#include <algorithm>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;
const int MAXM = 1000;

int solve() {
    int N, M;
    cin >> N >> M;

    vector<int> V(N), G(M);

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> G[i];
    }

    vector<vector<int>> T(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i <= N; i++) T[i][0] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++) {
            int match = (V[i - 1] < G[j - 1] ? 2 : 0);
            T[i][j] = max(T[i - 1][j - 1] + match, max(T[i - 1][j] + 1, T[i][j - 1]));
        }

    return T[N][M];
}

int main() {
    // se preferisci leggere e scrivere da file
    // ti basta decommentare le seguenti due righe:

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T, t;
    cin >> T;

    for (t = 1; t <= T; t++) {
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
