// leetcode - twoSum
// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            numMap[nums[i]] = i;
        }
        
        return {};
    }
};

int main() {
    Solution solution;
    
    // 테스트 케이스
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = solution.twoSum(nums1, target1);
    
    cout << "입력: [2, 7, 11, 15], 타겟: 9" << endl;
    cout << "결과: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "예상 결과: [0, 1]" << endl << endl;
    
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = solution.twoSum(nums2, target2);
    
    cout << "입력: [3, 2, 4], 타겟: 6" << endl;
    cout << "결과: [" << result2[0] << ", " << result2[1] << "]" << endl;
    cout << "예상 결과: [1, 2]" << endl << endl;
    
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = solution.twoSum(nums3, target3);
    
    cout << "입력: [3, 3], 타겟: 6" << endl;
    cout << "결과: [" << result3[0] << ", " << result3[1] << "]" << endl;
    cout << "예상 결과: [0, 1]" << endl;
    
    return 0;
}
