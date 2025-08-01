// baekjoon - p9375
// https://www.acmicpc.net/problem/9375

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        map<string, int> m;
        for (int j = 0; j < cnt; j++) {
            string _, clothes;
            cin >> _ >> clothes;
            m[clothes]++;
        }

        if (m.size() == 1) {
            cout << m.begin()-> second << '\n';
        } else {
            int sum = 1;
            for (const auto& pair : m) {
                sum *= (pair.second + 1);
            }
            cout << sum - 1 << '\n';
        }
    }
    
    return 0;
}
