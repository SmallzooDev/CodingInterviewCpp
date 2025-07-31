// baekjoon - p11655
// https://www.acmicpc.net/problem/11655

#include <cctype>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

char get_rot_13(char& c) {
    if (!isalpha(c)) return c;
    
    char base = islower(c) ? 'a' : 'A';
    int n = (c - base + 13) % 26;
    return base + n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string target;
    getline(cin, target);
    string res = "";

    for (auto &c : target) {
        res += get_rot_13(c);
    }

    
    cout << res << '\n';
    
    return 0;
}
