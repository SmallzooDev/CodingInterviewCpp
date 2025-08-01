// baekjoon - p4375
// https://www.acmicpc.net/problem/4375

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 문제 해결 코드 작성
    ll n;
    while (cin >> n) {
        ll num = 1;
        ll cnt = 1;

        while (num % n != 0) {
            num = (num * 10 + 1) % n;
            cnt++;
        }

        cout << cnt << '\n';
    }
    
    return 0;
}
