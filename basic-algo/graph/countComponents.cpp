// LINK: https://leetcode.com/problems/number-of-provinces

// TITLE: Find connected components of graph

// IDEA: Iterative DFS

#include <stack>
#include <vector>
using namespace std;

int connectedComponents(vector<vector<int>>& isConnected) {
    int n = isConnected.size();  // Returns the number of rows.
    vector<bool> visited(n, false);
    int r = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        r++;
        stack<int> dfsStack;
        dfsStack.push(i);

        while (!dfsStack.empty()) {
            // dfs
            int c = dfsStack.top();
            dfsStack.pop();

            if (visited[c]) continue;  // We may have pushed the neighbor twice
            visited[c] = true;

            for (int j = 0; j < n; j++) {
                if (!visited[j] && isConnected[c][j]) {
                    dfsStack.push(j);
                }
            }
        }
    }

    return r;
}

int main(int argc, char* argv[]) { return 0; }
