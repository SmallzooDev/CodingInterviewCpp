// baekjoon - p10870
// https://www.acmicpc.net/problem/10870

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibo(int num) {
    if (num == 1) return 1;
    if (num == 0) return 0;

    return fibo(num - 2) + fibo(num - 1);
}

int fibo2(int num) {
    vector<int> arr(num + 2, 0);
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < num + 1; i++) {
       arr[i] = arr[i - 1] + arr[i - 2];
    }

    return arr[num];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 문제 해결 코드 작성
    int n;
    cin >> n;
    cout << fibo2(n) <<'\n';
    
    return 0;
}

