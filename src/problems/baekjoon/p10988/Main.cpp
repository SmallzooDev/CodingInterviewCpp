// baekjoon - p10988
// https://www.acmicpc.net/problem/10988

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string target;
    cin >> target;

    int l, r;
    bool is_palin = true;
    l = 0; r = target.size() - 1;

    while (l <= r) {
        if (target[l] != target[r]) {
            is_palin = false;
            break;
        }

        l++; r--;
    }

    if (is_palin) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    
    
    return 0;
}
