// baekjoon - p1629
// https://www.acmicpc.net/problem/1629

#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll a,b,c;
    cin >> a >> b >> c;
    ll res = 1;
    a %= c;

    while (b > 0) {
        if (b % 2) {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b /= 2;
    }

    cout << res << '\n';
    
    return 0;
}
