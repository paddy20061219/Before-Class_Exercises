#include <iostream>
#include <vector>
using namespace std;

// LeetCode 658 - Find K Closest Elements
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        // 錯誤想法：直接回傳前 k 個元素
        // 但前 k 個元素不一定是最接近 x 的元素。
        for (int i = 0; i < k && i < arr.size(); i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
