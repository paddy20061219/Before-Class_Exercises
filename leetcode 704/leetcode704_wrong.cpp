#include <iostream>
#include <vector>
using namespace std;

// LeetCode 704 - Binary Search
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // 錯誤寫法：while 條件少了等於，會漏掉 left == right 的情況
        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
