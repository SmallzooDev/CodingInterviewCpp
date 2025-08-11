// baekjoon - p18258
// https://www.acmicpc.net/problem/18258

#include <deque>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

deque<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string query;
        cin >> query;
        if (query == "push") {
            int num;
            cin >> num;
            q.push_back(num);
        } else if (query == "pop") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
                q.pop_front();
            }
        } else if (query == "size") {
            cout << q.size() << '\n';
        } else if (query == "empty") {
            if (q.empty()) {
                cout << 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else if (query == "front") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.front() << '\n';
            }
        } else if (query == "back") {
            if (q.empty()) {
                cout << -1 << '\n';
            } else {
                cout << q.back() << '\n';
            }
        }
    }
    
    return 0;
}
