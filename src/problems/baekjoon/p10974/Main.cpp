// baekjoon - p10974
// https://www.acmicpc.net/problem/10974

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

void permute(vector<int> &arr, int start, int end) {
    if (start == end) {
        for (int num: arr) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= end; i++) {
        swap(arr[start], arr[i]);
        permute(arr, start + 1, end);
        swap(arr[start], arr[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 문제 해결 코드 작성
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 1; i < n + 1; i++) {
        arr.push_back(i);
    }

//    do {
//        for (int i: arr) {
//            cout << i << ' ';
//        }
//
//        cout << '\n';
//    } while (next_permutation(arr.begin(), arr.end()));
    permute(arr, 1, arr.size() -1);
    
    return 0;
}
