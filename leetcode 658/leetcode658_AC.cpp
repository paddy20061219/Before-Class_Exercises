#include <iostream>
#include <vector>
using namespace std;

// LeetCode 658 - Find K Closest Elements
// Correct version

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        // 二分搜尋最佳的連續區間起點
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 比較 x 距離左邊 arr[mid] 和右邊 arr[mid + k] 哪邊比較遠
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        vector<int> ans;
        for (int i = left; i < left + k; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
