// baekjoon - p1992
// https://www.acmicpc.net/problem/1992
 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;

bool is_all(int sy, int sx, int my, int mx) {
    int start = grid[sy][sx];
    for (int i = sy; i <= my; i++) {
        for (int j = sx; j <= mx; j++) {
            if (grid[i][j] != start) {
                return false;
            }
        }
    }
    return true;
}

string devide(int sy, int sx, int my, int mx) {
    if (is_all(sy, sx, my, mx)) {
        return to_string(grid[sy][sx]);
    }
    int hy = (sy + my) / 2;
    int hx = (sx + mx) / 2;
    string res = "";
    res += "(";
    res += devide(sy, sx, hy, hx);        
    res += devide(sy, hx+1, hy, mx);      
    res += devide(hy+1, sx, my, hx);      
    res += devide(hy+1, hx+1, my, mx);    
    res += ")";
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    grid = vector(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            grid[i][j] = tmp[j] - '0';
        }
    }
    
    cout << devide(0, 0, n-1, n-1) << "\n";
    
    return 0;
}
