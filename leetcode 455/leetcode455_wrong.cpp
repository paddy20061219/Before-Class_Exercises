#include <iostream>
#include <vector>
using namespace std;

// LeetCode 455 - Assign Cookies
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 蠢錯誤：直接回傳小孩數量
        // 題目要看餅乾夠不夠大，不是每個小孩一定都能滿足。
        return g.size();
    }
};
