// baekjoon - p10870
// https://www.acmicpc.net/problem/10870

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int fibonazzi(int num) {
    if (num == 1) return 1;
    if (num == 0) return 0;

    return fibonazzi(num - 2) + fibonazzi(num - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 문제 해결 코드 작성
    int n;
    cin >> n;
    cout << fibonazzi(n) <<'\n';
    
    return 0;
}

