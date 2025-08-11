// baekjoon - p2776
// https://www.acmicpc.net/problem/2776

#include <iostream>
#include <unordered_set>

// #include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int cases;
    cin >> cases;
    
    while (cases--) {
        unordered_set<int> notebook1;
        
        int num1;
        cin >> num1;
        for (int j = 0; j < num1; j++) {
            int tmp;
            cin >> tmp;
            notebook1.insert(tmp);
        }
        
        int num2;
        cin >> num2;
        for (int j = 0; j < num2; j++) {
            int tmp;
            cin >> tmp;
            if (notebook1.find(tmp) != notebook1.end()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
    }
    
    return 0;
}
