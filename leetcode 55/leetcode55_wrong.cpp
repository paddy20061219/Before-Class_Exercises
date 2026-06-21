#include <iostream>
#include <vector>
using namespace std;

// LeetCode 55 - Jump Game
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 蠢錯誤：完全不檢查能不能跳到最後
        // 直接說一定可以，遇到卡住的測資就會錯。
        return true;
    }
};
