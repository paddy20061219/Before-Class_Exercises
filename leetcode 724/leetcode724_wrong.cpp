#include <iostream>
#include <vector>
using namespace std;

// LeetCode 724 - Find Pivot Index
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        // 錯誤想法：只要左邊總和等於右邊總和就回傳
        // 但是這裡把目前 nums[i] 也算進右邊，導致判斷錯誤。
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = total - leftSum;

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
