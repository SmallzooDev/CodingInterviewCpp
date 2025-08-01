// baekjoon - p1213
// https://www.acmicpc.net/problem/1213

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

    string name;
    cin >> name;
    map<char, int> m;

    for (auto c : name) {
        m[c]++;
    }

    int odd_cnt = 0;
    char odd_char = 0;

    for (auto [ch, num] : m) {
        if (num % 2 == 1) {
            odd_cnt++;
            odd_char = ch;
        }
    }

    if (odd_cnt > 1) {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }

    string half;
    for (auto [ch, num] : m) {
        for (int i = 0; i < num /2; i++) {
            half += ch;
        }
    }

    string res = half;
    if (odd_char) res += odd_char;

    for (int i = half.length() - 1; i >= 0; i--) {
        res += half[i];
    }

    cout << res << '\n';
    return 0;
}
