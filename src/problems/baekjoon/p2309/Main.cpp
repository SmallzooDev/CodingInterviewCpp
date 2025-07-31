// baekjoon - p2309
// https://www.acmicpc.net/problem/2309

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> d = vector<int>();
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        int tmp;
        cin >> tmp;
        sum += tmp;
        d.push_back(tmp);
    }

    sort(d.begin(), d.end());
    

    int a, b;
    for (int i = 0; i < 9; i++) {
        bool found = false;
        for (int j = 1; j < 9; j++) {
            if (sum - d[i] - d[j] == 100) {
                a = i;
                b = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }


    for (int i =0; i < 9; i++) {
        if (i != a && i != b) {
            cout << d[i] << '\n';
        }
    }
    
    return 0;
}
