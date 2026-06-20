#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 179 - Largest Number
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // 錯誤想法：直接用字串由大到小排序
        // 但這樣不能保證接起來後是最大的數字。
        sort(arr.rbegin(), arr.rend());

        string ans = "";
        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};
