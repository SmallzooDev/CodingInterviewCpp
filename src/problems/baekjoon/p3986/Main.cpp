// baekjoon - p3986
// https://www.acmicpc.net/problem/3986

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

bool is_good_word(string word) {
    stack<char> s;
    for (auto c : word) {
        if (s.empty()) {
            s.push(c);
            continue;
        }

        if (s.top() == c) {
            s.pop();
        } else {
            s.push(c);
        }
    }

    return s.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    int res = 0;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        if (is_good_word(tmp)) {
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}
