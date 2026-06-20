#include <iostream>
#include <vector>
using namespace std;

// LeetCode 88 - Merge Sorted Array
// Correct version

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // 從後面開始放，避免覆蓋 nums1 前面還沒比較的數字
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // 如果 nums2 還有剩，就補到 nums1 前面
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
