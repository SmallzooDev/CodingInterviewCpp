// baekjoon - p32402
// https://www.acmicpc.net/problem/32402

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

pair<int, int> directions[] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

pair<int, int> camera_offsets[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; 
    cin >> n;
    
    pair<int, int> man = {0, 0};
    int camera_pos = 0;
    
    for (int i = 0; i < n; i++) {
        string query;
        cin >> query;
        
        if (query == "W") {
            auto dydx = directions[camera_pos];
            man.first += dydx.first;
            man.second += dydx.second;
        } else if (query == "D") {
            int right_dir = (camera_pos + 1) % 4;
            auto dydx = directions[right_dir];
            man.first += dydx.first;
            man.second += dydx.second;
        } else if (query == "S") {
            int back_dir = (camera_pos + 2) % 4;
            auto dydx = directions[back_dir];
            man.first += dydx.first;
            man.second += dydx.second;
        } else if (query == "A") {
            int left_dir = (camera_pos + 3) % 4;
            auto dydx = directions[left_dir];
            man.first += dydx.first;
            man.second += dydx.second;
        } else if (query == "MR") {
            camera_pos = (camera_pos + 1) % 4;
        } else if (query == "ML") {
            camera_pos = (camera_pos + 3) % 4;
        }
        
        pair<int, int> cam;
        cam.first = man.first + camera_offsets[camera_pos].first;
        cam.second = man.second + camera_offsets[camera_pos].second;
        
        cout << man.first << " " << man.second << " " << cam.first << " " << cam.second << "\n";
    }
    
    return 0;
}
