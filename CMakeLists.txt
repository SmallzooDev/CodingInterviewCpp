cmake_minimum_required(VERSION 3.10)
project(CodingInterviewCpp)

# C++17 표준 강제 적용
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 컴파일러 옵션 직접 추가 (gcc, clang 모두 지원)
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
endif()

# 모든 문제를 찾아서 빌드에 추가
file(GLOB_RECURSE PROBLEM_SOURCES "src/problems/*/*.cpp")

# 기본 실행 파일 (main.cpp)
add_executable(CodingInterviewCpp main.cpp)

# 각 문제 별로 실행 파일 생성
foreach(problem_source ${PROBLEM_SOURCES})
    # 파일 이름에서 경로와 확장자 제거
    get_filename_component(problem_name ${problem_source} NAME_WE)
    # 실행 파일 생성
    add_executable(${problem_name} ${problem_source})
endforeach()
