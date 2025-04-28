// baekjoon - p1759
// https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;
int plen;
int clen;
vector<char> carr;

bool is_valid_password(vector<char> &chars) {
    int vowel_count = 0;
    int consonant_count = 0;

    for (char c : chars) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowel_count++;
        } else if (c >= 'a' && c <= 'z') {
            consonant_count++;
        }
    }

    return (consonant_count >= 2 && vowel_count >= 1);
}

void combination(vector<char> &characters, int idx, int level, vector<char> &tmp) {
    if (level == plen) {
        if (is_valid_password(tmp)) {
            for (char c : tmp) {
                cout << c;
            }
            cout << '\n';
        }
        return;
    }

    for (int i = idx; i < characters.size(); i++) {
        tmp.push_back(characters[i]);
        combination(characters, i + 1, level + 1, tmp);
        tmp.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 문제 해결 코드 작성
    cin >> plen >> clen;
    for (int i = 0; i < clen; i++) {
       char tmp;
       cin >> tmp;
       carr.push_back(tmp);
    }

    std::sort(carr.begin(), carr.end());
    vector<char> tmp;
    combination(carr, 0, 0, tmp);
    return 0;
}
