// baekjoon - p6179
// https://www.acmicpc.net/problem/6179

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;


struct Roller {
    int x, y, r;
};

bool isTouching(const Roller& a, const Roller& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long distSq = dx * dx + dy * dy;
    long long sumR = a.r + b.r;
    return distSq == sumR * sumR;
}

pair<int, int> dfs(vector<Roller>& rollers, vector<vector<int>>& adj, 
                   vector<bool>& visited, int current) {
    visited[current] = true;
    
    for (int next : adj[current]) {
        if (!visited[next]) {
            return dfs(rollers, adj, visited, next);
        }
    }
    
    return {rollers[current].x, rollers[current].y};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<Roller> rollers(n);
    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    
    int idx = -1;
    
    for (int i = 0; i < n; i++) {
        cin >> rollers[i].x >> rollers[i].y >> rollers[i].r;
        
        if (rollers[i].x == 0 && rollers[i].y == 0) {
            idx = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isTouching(rollers[i], rollers[j])) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    
    pair<int, int> res = dfs(rollers, adj, visited, idx);    
    cout << res.first << " " << res.second << endl;
    
    return 0;
}
