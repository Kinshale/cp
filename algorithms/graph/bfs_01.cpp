// LINK: https://atcoder.jp/contests/abc213/tasks/abc213_e

// TITLE: Stronger Takahashi (bfs_01).

// We have a grid where:
//     . = Empty cell (can walk through freely)
//     # = Wall (cannot walk through)
// We start at (0,0) and want to reach (H-1, W-1).
// Special ability: We can use a bomb to destroy all walls in a 2×2 area centered around any cell we choose. Each bomb use costs 1.

// IDEA: This is a shortest distance problem, where each edge has either cost 0 (normal movement) or cost 1 (bombing).
// For implementing it we use 0-1 BFS, with a deque (double ended queue). This way we first process all nodes at distance 0, then all nodes at distance 1, then all nodes at distance 2 ...

#include <deque>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

class GridSolver {
   private:
    vector<vector<bool>> grid;
    int H, W;
    vector<vector<int>> dist;

    // Directions for normal movement (up, right, down, left)
    const int dx_normal[4] = {0, 1, 0, -1};
    const int dy_normal[4] = {1, 0, -1, 0};

    // Directions for bomb destruction (Manhattan distance ≤ 2)
    vector<pair<int, int>> bomb_directions;

    void initializeBombDirections() {
        for (int i = -2; i <= 2; i++) {
            for (int j = -2; j <= 2; j++) {
                if (abs(i) + abs(j) <= 2) {
                    bomb_directions.push_back({i, j});
                }
            }
        }
    }

    bool isValid(int x, int y) { return x >= 0 && x < H && y >= 0 && y < W; }

   public:
    GridSolver(vector<vector<bool>>& grid, int H, int W) : grid(grid), H(H), W(W) {
        initializeBombDirections();
        dist.assign(H, vector<int>(W, INF));
    }

    int solve() {
        deque<pair<int, int>> dq;
        dist[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            // If we reached the destination
            if (x == H - 1 && y == W - 1) {
                return dist[x][y];
            }

            // Process normal movement (cost 0)
            for (int i = 0; i < 4; i++) {
                int nx = x + dx_normal[i];
                int ny = y + dy_normal[i];

                if (isValid(nx, ny)) {
                    // If it's an empty cell and we found a cheaper path
                    if (grid[nx][ny] && dist[nx][ny] > dist[x][y]) {
                        dist[nx][ny] = dist[x][y];
                        dq.push_front({nx, ny});  // Cost 0 → push to front
                    }
                }
            }

            // Process bomb movement (cost 1)
            for (auto [dx, dy] : bomb_directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (isValid(nx, ny)) {
                    // We can reach any cell (empty or wall) with bomb
                    // But cost increases by 1
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        dq.push_back({nx, ny});  // Cost 1 → push to back
                    }
                }
            }
        }

        return dist[H - 1][W - 1];
    }
};

int main() {
    int H, W;
    cin >> H >> W;

    vector<vector<bool>> grid(H, vector<bool>(W, false));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char t;
            cin >> t;
            grid[i][j] = (t == '.');
        }
    }

    GridSolver solver(grid, H, W);
    int result = solver.solve();
    cout << result << endl;

    return 0;
}
