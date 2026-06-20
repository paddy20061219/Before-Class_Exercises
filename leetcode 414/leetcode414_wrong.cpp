#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 414 - Third Maximum Number
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 錯誤想法：排序後直接回傳第三個數字
        // 但題目要求的是「第三大的不重複數字」。
        sort(nums.rbegin(), nums.rend());

        if (nums.size() >= 3) {
            return nums[2];
        }

        return nums[0];
    }
};
