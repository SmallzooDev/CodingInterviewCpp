// baekjoon - p1159
// https://www.acmicpc.net/problem/1159

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
    int n;
    vector<int> names(26, 0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        names[*tmp.begin() - 'a'] +=1;
    }

    string res = "";
    for (int i = 0; i < 26; i++) {
        if (names[i] >= 5) {
            res += 'a' + i;
        }
    }
    
    if (res.size() >= 1) {
        cout << res << '\n';
    } else {
        cout << "PREDAJA" << '\n';
    }
    
    return 0;
}
