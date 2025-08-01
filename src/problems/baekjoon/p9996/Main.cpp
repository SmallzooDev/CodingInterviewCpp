// baekjoon - p9996
// https://www.acmicpc.net/problem/9996

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string pattern;
    cin >> n;
    cin >> pattern;

    int star_pos = pattern.find('*');
    string prefix = pattern.substr(0, star_pos);
    string suffix = pattern.substr(star_pos + 1);

    for (int i = 0; i < n; i++) {
        string target;
        cin >> target;

        if (target.size() < prefix.size() + suffix.size()) {
            cout << "NE" << '\n';
            continue;
        }

        bool starts_with = target.substr(0, prefix.size()) == prefix;
        bool ends_with = target.substr(target.size() - suffix.size()) == suffix;

        if (starts_with && ends_with) {
            cout << "DA" << '\n';
        } else {
            cout << "NE" << '\n';
        }
    }
    
    return 0;
}
