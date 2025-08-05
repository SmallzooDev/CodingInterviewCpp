// baekjoon - p21921
// https://www.acmicpc.net/problem/21921


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    
    vector<int> visitors(n);
    for (int i = 0; i < n; i++) {
        cin >> visitors[i];
    }
    
    int current_sum = 0;
    for (int i = 0; i < x; i++) {
        current_sum += visitors[i];
    }
    
    int max_sum = current_sum;
    int count = 1;
    
    for (int i = x; i < n; i++) {
        current_sum = current_sum - visitors[i - x] + visitors[i];
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            count = 1;
        } else if (current_sum == max_sum) {
            count++;
        }
    }
    
    if (max_sum == 0) {
        cout << "SAD\n";
    } else {
        cout << max_sum << "\n";
        cout << count << "\n";
    }
    
    return 0;
}
