// LINK: https://leetcode.com/problems/critical-connections-in-a-network/

// TITLE: Find Bridges (Edges that if removed, disconnect the graph).

// The algorithm builds a DFS spanning tree and classify edges:
//     Tree edges: Edges in the DFS tree
//     Back edges: Edges connecting to ancestors (creating cycles)
// It records discovery times in disc[u], and at each run tries to update low[u] an array that stores the earliest discovered node reachable from (not going backwards though).

// IDEA: If low[v] > disc[u], meaning that in the subgraph there isn't a node that can be discovered earlier, then (v; u) is a bridge.

#include <algorithm>
#include <vector>

using namespace std;

class findBridges {
   public:
    vector<vector<int>> adj;  // adjacency list
    vector<int> disc, low;    // discovery and low times
    vector<vector<int>> bridges;
    int timeCounter = 0;

    void dfs(int u, int parent) {
        disc[u] = low[u] = timeCounter++;

        for (int v : adj[u]) {
            if (v == parent) continue;  // ignore the edge to parent

            if (disc[v] == -1) {  // tree edge
                dfs(v, u);

                // Get the propagating up changes to low (We may have got a cycle)
                low[u] = min(low[u], low[v]);

                // bridge condition
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            } else {  // back edge
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vector<vector<int>> solve(int n, vector<vector<int>>& adj) {
        disc.assign(n, -1);
        low.assign(n, -1);
        timeCounter = 0;
        bridges.clear();

        // run DFS for all components
        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) dfs(i, -1);
        }

        return bridges;
    }
};

int main(int argc, char* argv[]) { return 0; }
