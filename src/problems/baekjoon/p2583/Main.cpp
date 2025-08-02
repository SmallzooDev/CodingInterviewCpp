// baekjoon - p2583
// https://www.acmicpc.net/problem/2583

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> grid;
vector<vector<int>> visited;

pair<int, int> movable[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int dfs(int x, int y, int cnt) {
    visited[x][y] = cnt;
    int area = 1;

    for (auto [dy, dx] : movable) {
        int ny = x + dy;
        int nx = y + dx;

        if (ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx] || grid[ny][nx]) continue;

        area += dfs(ny, nx, cnt);
    }
    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;
    grid = vector<vector<int>>(n, vector<int>(m, 0));
    visited = vector<vector<int>>(n, vector<int>(m, 0));

    for (int _ = 0; _ < k; _++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;

        for (int i = ly; i < ry; i++) {
            for (int j = lx; j < rx; j++) {
                grid[i][j] = 1;
            }
        }
    }

    int acc = 0;
    vector<int> areas;
    
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (grid[i][j] == 0 && visited[i][j] == 0) {
                acc++;
                areas.push_back(dfs(i, j, acc));
            }
        }
    }
    
    sort(areas.begin(), areas.end());
    
    cout << acc << '\n';
    for (int area : areas) {
        cout << area << ' ';
    }
    cout << '\n';
    
    return 0;
}
