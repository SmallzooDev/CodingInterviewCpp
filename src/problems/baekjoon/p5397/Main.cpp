// baekjoon - p5397
// https://www.acmicpc.net/problem/5397

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

string get_password(string s) {
    stack<char> l;
    stack<char> r;
    
    for (char c : s) {
        if (c == '<') {
            if (!l.empty()) {
                r.push(l.top());
                l.pop();
            }
        } else if (c == '>') {
            if (!r.empty()) {
                l.push(r.top());
                r.pop();
            }
        } else if (c == '-') {
            if (!l.empty()) {
                l.pop();
            }
        } else {
            l.push(c);
        }
    }
    
    vector<char> left_chars;
    vector<char> right_chars;
    
    while (!l.empty()) {
        left_chars.push_back(l.top());
        l.pop();
    }
    while (!r.empty()) {
        right_chars.push_back(r.top());
        r.pop();
    }
    
    string result;
    result.reserve(left_chars.size() + right_chars.size());
    
    for (int i = left_chars.size() - 1; i >= 0; i--) {
        result += left_chars[i];
    }

    for (char c : right_chars) {
        result += c;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cout << get_password(s) << '\n';
    }
    
    return 0;
}
