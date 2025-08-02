// baekjoon - p2828
// https://www.acmicpc.net/problem/2828

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 문제 해결 코드 작성
    int width, basket, cnt;
    cin >> width >> basket >> cnt;

    int l = 1;
    int r = basket;

    int res = 0;
    for (int i = 0; i < cnt; i++) {
        int tmp;
        cin >> tmp;

        if (tmp < l) {
            res += l - tmp;
            l = tmp;
            r = tmp + basket - 1;
        } else if (tmp > r) {
            res += tmp - r;
            r = tmp;
            l = tmp - basket + 1;
        }
    }
    

    cout << res << '\n';
    return 0;
}
