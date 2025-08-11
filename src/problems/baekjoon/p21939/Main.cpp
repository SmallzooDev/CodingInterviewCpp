// baekjoon - p21939
// https://www.acmicpc.net/problem/21939

#include <iostream>
#include <set>
#include <unordered_map>
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

    set<pair<int, int>> problems;
    unordered_map<int, int> problem_level;

    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        problems.insert({l, p});
        problem_level[p] = l;
    }

    int m;
    cin >> m;

    while (m--) {
        string query;
        cin >> query;

        if (query == "recommend") {
            int x;
            cin >> x;

            if (x == 1) {
                auto it = problems.rbegin();
                cout << it->second << '\n';
            } else {
                auto it = problems.begin();
                cout << it->second << '\n';
            }
        }
        else if (query == "add") {
            int p, l;
            cin >> p >> l;
            problems.insert({l, p});
            problem_level[p] = l;
        }
        else if (query == "solved") {
            int p;
            cin >> p;
            int l = problem_level[p];
            problems.erase({l, p});
            problem_level.erase(p);
        }
    }

    
    return 0;
}
