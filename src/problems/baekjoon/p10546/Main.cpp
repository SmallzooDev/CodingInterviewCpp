// baekjoon - p10546
// https://www.acmicpc.net/problem/10546

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
    
    int n; 
    cin >> n;
    
    unordered_map<string, int> count;
    
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        count[name]++;
    }
    
    for (int i = 0; i < n - 1; i++) {
        string name;
        cin >> name;
        count[name]--;
    }
    
    for (const auto& [name, cnt] : count) {
        if (cnt == 1) {
            cout << name << '\n';
            break;
        }
    }
    
    return 0;
}
