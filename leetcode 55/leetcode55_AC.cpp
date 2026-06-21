#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 55 - Jump Game
// AC version

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++){

            // 如果現在的位置 i 已經超過目前能到的最遠位置
            // 代表根本走不到這裡
            if(i > farthest){
                return false;
            }

            farthest = max(farthest, i + nums[i]);

            if(farthest >= nums.size() - 1){
                return true;
            }
        }

        return true;
    }
};
