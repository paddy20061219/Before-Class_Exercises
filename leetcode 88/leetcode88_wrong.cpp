#include <iostream>
#include <vector>
using namespace std;

// LeetCode 88 - Merge Sorted Array
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;

        // 錯誤想法：從前面開始合併，直接寫回 nums1
        // 但這樣會覆蓋 nums1 原本還沒使用到的數字。
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[k] = nums1[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }

        while (j < n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
