// baekjoon - p1620
// https://www.acmicpc.net/problem/1620

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cctype>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    map<int, string> poke_num;
    map<string, int> poke_name;
    
    for (int i = 1; i < n + 1; i++) {
        string tmp;
        cin >> tmp;
        poke_num[i] = tmp;
        poke_name[tmp] = i;
    }

    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (all_of(tmp.begin(), tmp.end(), ::isdigit)) {
            cout << poke_num[stoi(tmp)] << '\n';
        } else {
            cout << poke_name[tmp] << '\n';
        }
    }
    
    return 0;
}
