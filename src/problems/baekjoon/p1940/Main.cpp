// baekjoon - p1940
// https://www.acmicpc.net/problem/1940

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

    int n, m;
    cin >> n >> m;
    map<int, int> cmp;

    int res = 0;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if (cmp[tmp]) {
            res++;
        } else {
            cmp[m - tmp] = 1;
        }
    }
    
    cout << res << '\n';
    return 0;
}
