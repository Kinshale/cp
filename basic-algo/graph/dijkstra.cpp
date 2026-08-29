// LINK: https://cses.fi/problemset/task/1196

// TITLE: Find the k shortest paths between two cities. We can rivisit the same city.

// IDEA: Djikstra, which is a standard BFS with a priority queue, with a twist: we store the k shortest path for each node.

#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int dijkstra(int n, int m, vector<vector<pair<int, int>>> adj) {
    using pii = pair<int, int>;                        // (distance, node)
    priority_queue<pii, vector<pii>, greater<pii>> q;  // We need a min-heap (IDK why greater and not less than).

    vector<int> dist(n, INT_MAX);
    vector<bool> processed(n, false);

    // NOTE: We start at 0 and end at n

    dist[1] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        if (processed[v]) continue;
        processed[v] = true;

        // Early termination check
        if (v == n - 1) break;

        for (auto [u, w] : adj[v]) {
            // OPTIMIZATION: Instead of updating the distances when we pop the node (guaranteed to be the minimum path),
            // we add a relaxation check here (we may push the same node multiple times into the queue).
            if (dist[u] > d + w) {
                dist[u] = d + w;
                q.push({dist[u], u});
            }
        }
    }

    return dist[n - 1];
}

vector<long long> multipleDijkstra(int n, int m, int k, const vector<vector<pair<int, int>>>& adj) {
    using pll = pair<long long, int>;
    priority_queue<pll, vector<pll>, greater<pll>> pq;

    // dist[i] = list of up to k shortest distances to node i
    vector<vector<long long>> dist(n);

    pq.push({0, 0});  // (cost, node)

    while (!pq.empty()) {
        auto [cost, node] = pq.top();
        pq.pop();

        // If we already have k distances for this node, skip it
        if (dist[node].size() >= (size_t)k) continue;

        // The pq guarantees we pick each time the shortest distance
        dist[node].push_back(cost);

        // Early termination check.
        if (node == n - 1 && dist[node].size() == (size_t)k) break;

        // Explore neighbors
        for (auto [next, w] : adj[node]) pq.push({cost + w, next});
    }

    return dist[n - 1];  // k shortest distances to destination
}

// WARNING: Most of graph problems are 1-based. Here I use 0-index and manually adjust when acquiring and printing data.

int main(int argc, char* argv[]) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        a--;
        b--;

        adj[a].push_back({b, c});
    }

    auto result = multipleDijkstra(n, m, k, adj);
    for (auto r : result) {
        cout << r << " ";
    }
    cout << "\n";

    return 0;
}
