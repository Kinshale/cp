// LINK: https://cses.fi/problemset/task/1675

// TITLE: Road Reparation.
// IDEA: Basic MST (Kurskal Algorithm).

#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

struct DSU {
    vector<int> parent, size;

    // Constructor: initialize DSU for n elements (1-indexed);
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    //  USE: find(x) == find(y).
    int find(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    int unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (size[a] < size[b]) swap(a, b);

        size[a] += size[b];
        parent[b] = a;

        // INSIGHT: Union by Rank (size): Attach the smaller tree to the larger
        // one to keep the structure flat.
        return true;
    }
};

long long mst(int n, int m, vector<array<int, 3>> edges) {
    long long w = 0;
    int edge_count = 0;

    DSU dsu(n);

    // NOTE: Lambda syntax (Third argument)
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
        return a[2] < b[2];  // Sort by weight
    });

    for (auto& e : edges) {
        if (dsu.unite(e[0], e[1])) {
            w += e[2];
            edge_count++;
        }
    }

    // If we don't have n-1 edges, the graph is disconnected
    if (edge_count < n - 1) return -1;  // no MST exists

    return w;
}

int main(int argc, char* argv[]) {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; ++i) cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

    long long ans = mst(n, m, edges);
    if (ans == -1) cout << "IMPOSSIBLE" << endl;
    else cout << ans << endl;

    return 0;
}
