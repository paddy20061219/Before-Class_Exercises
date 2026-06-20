#include <iostream>
#include <vector>
#include <set>
using namespace std;

// LeetCode 414 - Third Maximum Number
// Correct version

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;

        // set 會自動去除重複元素，並且保持排序
        for (int num : nums) {
            s.insert(num);
        }

        // 如果不同的數字少於 3 個，就回傳最大值
        if (s.size() < 3) {
            return *s.rbegin();
        }

        // 刪掉最大值
        s.erase(*s.rbegin());

        // 刪掉第二大值
        s.erase(*s.rbegin());

        // 現在最大的就是第三大值
        return *s.rbegin();
    }
};
