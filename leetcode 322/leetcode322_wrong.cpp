#include <iostream>
#include <vector>
using namespace std;

// LeetCode 322 - Coin Change
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 蠢錯誤：直接回傳 amount
        // 題目要的是最少硬幣數，不是金額是多少。
        return amount;
    }
};
