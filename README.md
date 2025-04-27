# C++ 코딩 인터뷰 관리 프로젝트

CLion을 이용한 코딩 인터뷰 문제 풀이 및 관리 프로젝트입니다.

## 프로젝트 구조

```
CodingInterviewCpp/
├── src/
│   └── problems/
│       ├── leetcode/
│       │   └── [problem_name]/
│       │       ├── Solution.cpp
│       │       └── README.md
│       └── baekjoon/
│           └── [problem_name]/
│               ├── Main.cpp
│               └── README.md
├── init.sh        # 문제 생성 스크립트
├── main.cpp       # 메인 프로그램
├── CMakeLists.txt # CMake 설정 파일
└── README.md      # 이 파일
```

## 사용 방법

### 새 문제 생성

LeetCode나 백준 문제 URL을 이용해 새 문제를 추가할 수 있습니다:

```bash
./init.sh <문제_URL>
```

예시:
```bash
./init.sh https://leetcode.com/problems/two-sum/
./init.sh https://www.acmicpc.net/problem/1000
```

### 문제 목록 확인

메인 프로그램을 실행하여 등록된 문제 목록을 확인할 수 있습니다:

```bash
./CodingInterviewCpp
```

### 문제 해결 및 빌드

1. CLion IDE에서 해당 문제 파일(Solution.cpp 또는 Main.cpp)을 열어 코드를 작성합니다.
2. CMake 설정에 의해 각 문제별로 별도의 빌드 타겟이 생성됩니다.
3. CLion의 빌드/실행 구성에서 원하는 문제 타겟을 선택하여 빌드하고 실행할 수 있습니다.

## 시스템 요구사항

- CMake 3.10 이상
- C++17 지원 컴파일러
- CLion IDE (권장) 