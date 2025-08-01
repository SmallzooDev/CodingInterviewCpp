// baekjoon - p12755
// https://www.acmicpc.net/problem/12755

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n;
    cin >> n;

    long long digits = 1;
    long long count = 9;
    long long start = 1;

    while (n > digits * count) {
        n -= digits * count;
        digits++;
        count *= 10;
        start *= 10;
    }

    long long number = start + (n - 1) / digits;
    int idx = (n - 1) % digits;

    string numStr = to_string(number);
    cout << numStr[idx] << '\n';
    
    return 0;
}
