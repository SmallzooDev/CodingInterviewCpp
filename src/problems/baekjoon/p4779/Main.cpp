// baekjoon - p4779
// https://www.acmicpc.net/problem/4779

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

string create_string(int n) {
    int length = pow(3, n);
    return string(length, '-');
}

void cantore(string& str, int start, int length) {
    if (length == 1) return;

    int partial = length / 3;

    for (int i = start + partial; i < start + 2 * partial; i++) {
        str[i] = ' ';
    }

    cantore(str, start, partial);
    cantore(str, start + 2 * partial, partial);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        string result = create_string(n);
        cantore(result, 0, pow(3, n));
        cout << result << '\n';
    }

    return 0;
}