// baekjoon - p2559
// https://www.acmicpc.net/problem/2559

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k,first;
    vector<int> temps;

    cin >> n >> k;
    cin >> first;
    temps.push_back(first);
    

    for (int i = 1; i < n; i++) {
        int tmp;
        cin >> tmp;
        temps.push_back(tmp + temps[i - 1]);
    }

    int m = temps[k-1];
    int l = 0;
    int r = k;
    
    while (r < temps.size()) {
        m = max(m, temps[r] - temps[l]);
        r++; l++;
    }

    cout << m << '\n';
    return 0;
}
