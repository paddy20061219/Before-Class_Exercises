#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 950 - Reveal Cards In Increasing Order
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // 錯誤想法：直接把牌由小到大排序後回傳
        // 但題目要的是「原本牌堆的排列」，不是翻出來後的順序。
        sort(deck.begin(), deck.end());

        return deck;
    }
};
