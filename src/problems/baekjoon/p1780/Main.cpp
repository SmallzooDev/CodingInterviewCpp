// baekjoon - p1780
// https://www.acmicpc.net/problem/1780

#include <iostream>
#include <vector>

// #include <bits/stdc++.h>
using namespace std;

int n;
vector<int> res = vector<int>(3, 0);

int is_uniform(
    vector<vector<int>>& graph,
    int start_row,
    int end_row,
    int start_col,
    int end_col
) {
    int first = graph[start_row][start_col];
    for (int i = start_row; i < end_row; i++) {
        for (int j = start_col; j < end_col; j++) {
            if (graph[i][j] != first) {
                return -99;
            }
        }
    }
    return first;
}

void split_papers(
    vector<vector<int>>& graph,
    int start_row,
    int end_row,
    int start_col,
    int end_col
) {
    int checked = is_uniform(graph, start_row, end_row, start_col, end_col);
    
    if (checked != -99) {
        // 균일한 경우 카운트 증가
        if (checked == -1) {
            res[0]++;
        } else if (checked == 0) {
            res[1]++;
        } else if (checked == 1) {
            res[2]++;
        }
        return;
    }
    
    int size = (end_row - start_row) / 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int new_start_row = start_row + i * size;
            int new_end_row = new_start_row + size;
            int new_start_col = start_col + j * size;
            int new_end_col = new_start_col + size;
            
            split_papers(graph, new_start_row, new_end_row, new_start_col, new_end_col);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    vector<vector<int>> papers(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> papers[i][j];
        }
    }
    
    split_papers(papers, 0, n, 0, n);
    
    cout << res[0] << "\n";  // -1의 개수
    cout << res[1] << "\n";  // 0의 개수
    cout << res[2] << "\n";  // 1의 개수
    
    return 0;
}
