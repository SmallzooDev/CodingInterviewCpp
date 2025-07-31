// baekjoon - p2979
// https://www.acmicpc.net/problem/2979

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    vector<int> park(101, 0);
    int m = 0;

    cin >> a >> b >> c;
    
    for (int i = 0; i < 3; i++) {
        int start, end;
        cin >> start >> end;
        
        m = max(m, end);
        
        for (int j = start; j < end; j++) {
            park[j]++;
        }
    }

    int res = 0;
    
    for (int i = 1; i < m; i++) {
        if (park[i] == 1) res += a;
        else if (park[i] == 2) res += b * 2;
        else if (park[i] == 3) res += c * 3;
    }

    cout << res << '\n';
    return 0;
}
