// baekjoon - p2238
// https://www.acmicpc.net/problem/2238

#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

int main() {
    int U, N;
    cin >> U >> N;
    
    map<int, int> priceCount;
    
    map<int, pair<string, int>> firstBidder;
    
    for (int i = 0; i < N; i++) {
        string name;
        int price;
        cin >> name >> price;
        
        priceCount[price]++;
        
        if (firstBidder.find(price) == firstBidder.end()) {
            firstBidder[price] = make_pair(name, i);
        }
    }
    
    int minCount = INT_MAX;
    for (auto& p : priceCount) {
        minCount = min(minCount, p.second);
    }
    
    int winningPrice = INT_MAX;
    for (auto& p : priceCount) {
        if (p.second == minCount) {
            winningPrice = min(winningPrice, p.first);
        }
    }
    
    cout << firstBidder[winningPrice].first << " " << winningPrice << endl;
    
    return 0;
}
