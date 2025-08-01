// baekjoon - p2468
// https://www.acmicpc.net/problem/2468

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

pair<int, int> movable[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, max_h;
vector<vector<int>> grid;

void dfs(int y, int x, vector<vector<int>>& visited, vector<vector<int>>& rain_grid) {
    visited[y][x] = 1;
    rain_grid[y][x] = 0;

    for (auto [dy, dx] : movable) {
        int ny = y + dy;
        int nx = x + dx;

        if (ny >= n || nx >= n || ny < 0 || nx < 0 || visited[ny][nx] || rain_grid[ny][nx] == 0) {
            continue;
        }

        dfs(ny, nx, visited, rain_grid);
    }
    
    
}

int get_safe_area_cnt(int height) {
    int res = 0;
    vector<vector<int>> rain_grid(n, vector(n, 0));
    vector<vector<int>> visited(n, vector(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] <= height) {
                rain_grid[i][j] = 0;
            } else {
                rain_grid[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rain_grid[i][j] == 1) {
                res++;
                dfs(i, j, visited, rain_grid);
            }
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    grid = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            max_h = max(max_h, grid[i][j]);
        }
    }


    int res = 1;
    for (int i = 0; i <= max_h; i++) {
        int cnt = get_safe_area_cnt(i);
        res = max(res, cnt);
    }
    
    
    cout << res << '\n';
    return 0;
}