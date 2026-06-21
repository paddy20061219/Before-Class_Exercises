#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LeetCode 228 - Summary Ranges
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        // 蠢錯誤：直接把每個數字都丟進答案
        // 題目要把連續的數字合併成範圍，不是全部分開。
        for(int i=0;i<nums.size();i++){
            ans.push_back(to_string(nums[i]));
        }

        return ans;
    }
};
