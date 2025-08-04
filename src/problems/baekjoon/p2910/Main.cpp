// baekjoon - p2910
// https://www.acmicpc.net/problem/2910

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c;
    cin >> n >> c;
    
    vector<int> sequence(n);
    map<int, int> count;
    map<int, int> first_pos;
    
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
        count[sequence[i]]++;
        
        if (first_pos.find(sequence[i]) == first_pos.end()) {
            first_pos[sequence[i]] = i;
        }
    }
    
    vector<int> unique_nums;
    for (auto& p : count) {
        unique_nums.push_back(p.first);
    }
    
    sort(unique_nums.begin(), unique_nums.end(), [&](int a, int b) {
        if (count[a] != count[b]) {
            return count[a] > count[b];
        }
        return first_pos[a] < first_pos[b];
    });
    
    for (int num : unique_nums) {
        for (int i = 0; i < count[num]; i++) {
            cout << num << " ";
        }
    }
    cout << "\n";
    
    return 0;
}
