// baekjoon - p10808
// https://www.acmicpc.net/problem/10808

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> res(26, 0);
    string str;
    cin >> str;

    for (auto &a : str) {
        res[a - 'a'] += 1;
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << ' ';
    }
    
    return 0;
}
