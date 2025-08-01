// baekjoon - p1012
// https://www.acmicpc.net/problem/1012

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

pair<int, int> movable[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
vector<vector<int>> visited;
vector<vector<int>> grid;
int m, n, k;

void dfs(int y, int x) {
    visited[y][x] = 1;
    grid[y][x] = 0;
    
    for (auto [dy, dx] : movable) {
        int ny = y + dy;
        int nx = x + dx;

        if (ny >= n || nx >= m || ny < 0 || nx < 0  || visited[ny][nx] || grid[ny][nx] == 0) {
            continue;
        }

        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cases;
    cin >> cases;
    for (int cnt = 0; cnt < cases; cnt++) {
        cin >> m >> n >> k;

        visited = vector(n, vector<int>(m, 0));
        grid = vector(n, vector<int>(m, 0));

        for (int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            grid[y][x] = 1;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                   res += 1;
                   dfs(i, j); 
                }
            }
        }

        cout << res << '\n';
    }
    return 0;
}
