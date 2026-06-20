#include <iostream>
#include <vector>
using namespace std;

// LeetCode 724 - Find Pivot Index
// Correct version

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // 右邊總和不能包含目前 nums[i]
            int rightSum = total - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
