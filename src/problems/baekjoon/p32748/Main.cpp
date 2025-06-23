// baekjoon - p32748
// https://www.acmicpc.net/problem/32748

#include <iostream>
#include <string>
#include <vector>
// #include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> p(10), q(10);
  for (int i = 0; i < 10; i++) {
    int x;
    cin >> x;
    p[i] = x;
    q[x] = i;
  }

  string fa, fb;
  cin >> fa >> fb;
  string a, b;
  for (char c : fa)
    a += to_string(q[c - '0']);
  for (char c : fb)
    b += to_string(q[c - '0']);
  string d = to_string(stoi(a) + stoi(b));
  for (char c : d)
    cout << p[c - '0'];
}
