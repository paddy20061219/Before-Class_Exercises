#include <iostream>
#include <vector>
using namespace std;

// LeetCode 169 - Majority Element
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 錯誤想法：直接回傳第一個數字
        // 但出現超過一半的數字不一定在第一個位置。
        return nums[0];
    }
};
