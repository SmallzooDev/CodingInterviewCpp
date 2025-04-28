// baekjoon - p6603
// https://www.acmicpc.net/problem/6603

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

void combination(vector<int> &arr, int index, int level, vector<int> &tmp) {
    if (level == 6) {
        for (int i = 0; i < tmp.size(); i++) {
            cout << tmp[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = index; i < arr.size(); i++) {
        tmp.push_back(arr[i]);
        combination(arr, i + 1, level + 1, tmp);
        tmp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 문제 해결 코드 작성
    while (true) {
        int count;
        cin >> count;
        if (count == 0) break;

        vector<int> numbers;
        for (int i = 0; i < count; i++) {
            int num;
            cin >> num;
            numbers.push_back(num);
        }

        vector<int> tmp;
        combination(numbers, 0, 0,tmp);
        cout << '\n';
    }
    
    return 0;
}
