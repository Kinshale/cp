// LINK: https://cses.fi/problemset/task/1196

// TITLE: Flight Routes (Find the k shortest paths between two cities)

// IDEA: Djikstra, which is a standard BFS with a priority queue.

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

    dist[0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto [d, v] = q.top();
        q.pop();

        if (processed[v]) continue;
        processed[v] = true;

        // Early termination check
        if (v == n - 1) break;

        for (auto [u, w] : adj[v]) {
            // We may push the same node multiple times from different
            // neighbors. To avoid this ...
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

        dist[node].push_back(cost);

        // Early termination check.
        if (node == n - 1 && dist[node].size() == (size_t)k) break;

        // Explore neighbors
        for (auto [next, w] : adj[node]) {
            long long new_cost = cost + w;
            pq.push({new_cost, next});
        }
    }

    return dist[n - 1];  // k shortest distances to destination
}

int main(int argc, char* argv[]) {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        adj[a].push_back({b, c});
    }

    return 0;
}
