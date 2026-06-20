#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 179 - Largest Number
// Correct version

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // 如果 a + b 比 b + a 大，代表 a 應該排在 b 前面
        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        // 處理全部都是 0 的情況
        if (arr[0] == "0") {
            return "0";
        }

        string ans = "";
        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};
