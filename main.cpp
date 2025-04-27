#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

namespace fs = std::filesystem;

const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";

void printHeader() {
    std::cout << BOLD << GREEN << "====================================" << RESET << std::endl;
    std::cout << BOLD << GREEN << "    C++ 코딩 인터뷰 문제 관리     " << RESET << std::endl;
    std::cout << BOLD << GREEN << "====================================" << RESET << std::endl;
}

void listProblems() {
    std::cout << BOLD << "등록된 문제 목록:" << RESET << std::endl;
    
    std::vector<std::string> sites = {"leetcode", "baekjoon"};
    for (const auto& site : sites) {
        std::string path = "src/problems/" + site;
        
        try {
            if (!fs::exists(path)) continue;
            
            std::cout << BOLD << BLUE << "\n[" << site << "]" << RESET << std::endl;
            
            std::vector<std::string> problems;
            for (const auto& entry : fs::directory_iterator(path)) {
                if (entry.is_directory()) {
                    problems.push_back(entry.path().filename().string());
                }
            }
            
            std::sort(problems.begin(), problems.end());
            
            for (const auto& problem : problems) {
                std::string readme_path = path + "/" + problem + "/README.md";
                std::string url = "";
                
                if (fs::exists(readme_path)) {
                    std::ifstream readme(readme_path);
                    std::string line;
                    while (std::getline(readme, line)) {
                        if (line.find("url :") != std::string::npos) {
                            url = line.substr(line.find("url :") + 6);
                            break;
                        }
                    }
                }
                
                std::cout << YELLOW << " - " << problem << RESET;
                if (!url.empty()) {
                    std::cout << " (" << url << ")";
                }
                std::cout << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << RED << "오류: " << e.what() << RESET << std::endl;
        }
    }
}

void showHelp() {
    std::cout << BOLD << "사용 방법:" << RESET << std::endl;
    std::cout << "1. 새 문제 생성: ./init.sh <문제_URL>" << std::endl;
    std::cout << "2. 문제 확인: CLion에서 해당 문제 파일 열기" << std::endl;
    std::cout << "3. 문제 빌드 및 실행: CLion에서 해당 타켓 선택 후 빌드/실행" << std::endl;
}

int main() {
    printHeader();
    std::cout << std::endl;
    
    listProblems();
    std::cout << std::endl;
    
    showHelp();
    
    return 0;
}
