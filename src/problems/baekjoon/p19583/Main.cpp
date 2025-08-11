// baekjoon - p19583
// https://www.acmicpc.net/problem/19583

#include <iostream>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

vector<string> split(string s, char delimeter) {
    vector<string> result;
    stringstream ss(s);
    string token;
    while (getline(ss, token, delimeter)) {
        result.push_back(token);
    }
    return result;
}

int to_time(string s) {
    vector<string> spl = split(s, ':');
    return stoi(spl[0]) * 60 + stoi(spl[1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string start, end, streaming_end; 
    cin >> start >> end >> streaming_end;
    
    int sn = to_time(start);
    int en = to_time(end);
    int ssn = to_time(streaming_end);
    
    unordered_set<string> before_start;
    unordered_set<string> after_end;
    
    string time, id;
    while (cin >> time >> id) {
        int time_n = to_time(time);
        
        if (time_n <= sn) {
            before_start.insert(id);
        } 
        if (time_n >= en && time_n <= ssn) {
            after_end.insert(id);
        }
    }
    
    int res = 0;
    for (const string& person : before_start) {
        if (after_end.count(person)) {
            res++;
        }
    }
    
    cout << res << '\n';
    return 0;
}
