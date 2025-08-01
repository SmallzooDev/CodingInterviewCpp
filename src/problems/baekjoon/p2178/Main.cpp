// baekjoon - p2178
// https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;
pair<int, int> movable[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;

        for (int j = 0; j < m; j++) {
            graph[i][j] = tmp[j] - '0';
        }
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        for (auto [dy, dx] : movable) {
            int ny = y + dy;
            int nx = x + dx;

            if (ny >= n || nx >= m || ny < 0 || nx < 0 || visited[ny][nx] != -1 || graph[ny][nx] == 0) {
                continue;
            }

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[n - 1][m - 1] << '\n';
    return 0;
}
