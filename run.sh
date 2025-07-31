#!/bin/bash

# 문제 실행 스크립트
# 사용법: ./run.sh <문제번호>

if [ $# -lt 1 ]; then
    echo "사용법: $0 <문제번호>"
    echo "예시: $0 1001"
    exit 1
fi

PROBLEM_NUM=$1

# 백준 문제 찾기
BAEKJOON_DIR="src/problems/baekjoon/p${PROBLEM_NUM}"
if [ -d "$BAEKJOON_DIR" ]; then
    PROBLEM_DIR="$BAEKJOON_DIR"
    CPP_FILE="$BAEKJOON_DIR/Main.cpp"
    EXEC_NAME="main"
elif [ -d "src/problems/baekjoon/${PROBLEM_NUM}" ]; then
    PROBLEM_DIR="src/problems/baekjoon/${PROBLEM_NUM}"
    CPP_FILE="src/problems/baekjoon/${PROBLEM_NUM}/Main.cpp"
    EXEC_NAME="main"
else
    echo "오류: 문제 번호 $PROBLEM_NUM을 찾을 수 없습니다."
    echo "경로 확인: src/problems/baekjoon/p${PROBLEM_NUM} 또는 src/problems/baekjoon/${PROBLEM_NUM}"
    exit 1
fi

if [ ! -f "$CPP_FILE" ]; then
    echo "오류: $CPP_FILE 파일을 찾을 수 없습니다."
    exit 1
fi

echo "문제 찾음: $PROBLEM_DIR"
echo "컴파일 중: $CPP_FILE"

# 컴파일
cd "$PROBLEM_DIR"
if g++ -o "$EXEC_NAME" Main.cpp -std=c++17 -Wall -Wextra -O2; then
    echo "컴파일 성공!"
    echo "실행 중..."
    echo "----------------------------------------"
    ./"$EXEC_NAME"
    echo "----------------------------------------"
    echo "실행 완료!"
else
    echo "컴파일 오류 발생!"
    exit 1
fi