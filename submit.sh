#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <problem_number>"
    exit 1
fi

problem_num=$1
file_path="src/problems/baekjoon/p${problem_num}/Main.cpp"

if [ ! -f "$file_path" ]; then
    echo "File not found: $file_path"
    exit 1
fi

# bits/stdc++.h 라인을 찾고 그 라인부터 끝까지 복사
# 주석을 해제하고 클립보드에 복사
sed -n '/\/\/ #include <bits\/stdc++\.h>/,$p' "$file_path" | \
sed 's|^// \(#include <bits/stdc++\.h>\)|\1|' | \
pbcopy

echo "Code copied to clipboard from line containing #include <bits/stdc++.h> to end of file"