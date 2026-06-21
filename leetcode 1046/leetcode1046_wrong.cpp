#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1046 - Last Stone Weight
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 蠢錯誤：直接回傳石頭數量
        // 題目要的是最後剩下的重量，不是剩幾顆石頭。
        return stones.size();
    }
};
