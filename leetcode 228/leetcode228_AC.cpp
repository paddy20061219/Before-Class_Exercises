#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LeetCode 228 - Summary Ranges
// AC version

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        int i = 0;

        while(i < n){
            int start = nums[i];

            // 找這一段連續數字的最後一個
            while(i + 1 < n && (long long)nums[i] + 1 == nums[i + 1]){
                i++;
            }

            int end = nums[i];

            if(start == end){
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }

            i++;
        }

        return ans;
    }
};
