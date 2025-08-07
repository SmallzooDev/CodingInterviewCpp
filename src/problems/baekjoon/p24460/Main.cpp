// baekjoon - p24460
// https://www.acmicpc.net/problem/24460

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> grid;

int get_winner(int sx, int ex, int sy, int ey) {
    if (sx == ex && sy == ey) {
        return grid[sy][sx];
    }
    
    int mx = (sx + ex) / 2;
    int my = (sy + ey) / 2;
    
    vector<int> res;
    res.push_back(get_winner(sx, mx, sy, my));       
    res.push_back(get_winner(mx + 1, ex, sy, my));    
    res.push_back(get_winner(sx, mx, my + 1, ey));    
    res.push_back(get_winner(mx + 1, ex, my + 1, ey));
    
    sort(res.begin(), res.end());
    return res[1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    grid.resize(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    cout << get_winner(0, n - 1, 0, n - 1) << '\n';
    
    return 0;
}
