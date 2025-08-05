// baekjoon - p15720
// https://www.acmicpc.net/problem/15720

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;
int total_before = 0;

priority_queue<int> get_inputs(int size) {
    priority_queue<int> res;
    for (int i = 0; i < size; i++) {
        int tmp;
        cin >> tmp;
        total_before += tmp;
        res.push(tmp);
    }
    return res;
}

int get_sum(priority_queue<int> q) {
    int res = 0;
    while (!q.empty()) {
        res += q.top();
        q.pop();
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int a, b, c;
    cin >> a >> b >> c;
    
    auto ah = get_inputs(a);
    auto bh = get_inputs(b);
    auto ch = get_inputs(c);
    
    
    int total_after = 0;
    
    while (!ah.empty() && !bh.empty() && !ch.empty()) {
        int set_price = ah.top() + bh.top() + ch.top();
        total_after += set_price * 9 / 10; 
        ah.pop();
        bh.pop();
        ch.pop();
    }
    
    total_after += get_sum(ah);
    total_after += get_sum(bh);
    total_after += get_sum(ch);
    
    cout << total_before << '\n';
    cout << total_after << '\n';
    
    return 0;
}
