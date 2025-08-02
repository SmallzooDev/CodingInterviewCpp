// baekjoon - p5587
// https://www.acmicpc.net/problem/5587
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> s(n);
    vector<bool> used(2*n + 1, false);
    
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        used[s[i]] = true;
    }
    
    vector<int> k;
    for (int i = 1; i <= 2*n; i++) {
        if (!used[i]) {
            k.push_back(i);
        }
    }
    
    sort(s.begin(), s.end());
    sort(k.begin(), k.end());
    
    vector<bool> s_used(n, false);
    vector<bool> k_used(n, false);
    
    int current_card = 0;
    bool s_turn = true; 
    
    while (true) {
        bool can_play = false;
        
        if (s_turn) {
            for (int i = 0; i < n; i++) {
                if (!s_used[i] && s[i] > current_card) {
                    s_used[i] = true;
                    current_card = s[i];
                    can_play = true;
                    break;
                }
            }
            
            if (!can_play) {
                current_card = 0;
            }
            s_turn = false;
        } else {
            for (int i = 0; i < n; i++) {
                if (!k_used[i] && k[i] > current_card) {
                    k_used[i] = true;
                    current_card = k[i];
                    can_play = true;
                    break;
                }
            }
            
            if (!can_play) {
                current_card = 0;
            }
            s_turn = true;
        }
        
        int s_remaining = 0, k_remaining = 0;
        for (int i = 0; i < n; i++) {
            if (!s_used[i]) s_remaining++;
            if (!k_used[i]) k_remaining++;
        }
        
        if (s_remaining == 0 || k_remaining == 0) {
            cout << k_remaining << "\n";
            cout << s_remaining << "\n";
            break;
        }
    }
    
    return 0;
}
