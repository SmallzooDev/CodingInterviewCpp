// baekjoon - p12764
// https://www.acmicpc.net/problem/12764

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>
using namespace std;

struct Person {
  int start, end;  
  bool operator<(const Person& other) const {
      return start < other.start;
  }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Person> p;
    p.reserve(n + 1);
    for (int i = 0; i< n; i++) {
        Person person;
        cin >> person.start >> person.end;
        p.push_back(person);
    }

    sort(p.begin(), p.end());
    vector<int> pcs;
    vector<int> usg;

    for (int i = 0; i < n; i++) {
        int start = p[i].start;
        int end = p[i].end;

        int assigned = -1;
        for (int j = 0; j < pcs.size(); j++) {
            if (pcs[j] <= start) {
                assigned = j;
                break;
            }
        }

        if (assigned == -1) {
            pcs.push_back(end);
            usg.push_back(1);
        } else {
            pcs[assigned] = end;
            usg[assigned]++;
        }
    }

    cout << pcs.size() << '\n';
    for (int i = 0; i < usg.size(); i++) {
        cout << usg[i];
        if (i < usg.size() - 1) cout << " ";
    }

    cout << '\n';
    
    return 0;
}
