#include <iostream>
#include <string>
using namespace std;

// LeetCode 20 - Valid Parentheses
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool isValid(string s) {
        int round = 0;
        int square = 0;
        int curly = 0;

        // 錯誤想法：只計算每種括號數量是否相同
        // 但沒有檢查括號的順序和配對位置。
        for (char c : s) {
            if (c == '(') round++;
            else if (c == ')') round--;
            else if (c == '[') square++;
            else if (c == ']') square--;
            else if (c == '{') curly++;
            else if (c == '}') curly--;
        }

        return round == 0 && square == 0 && curly == 0;
    }
};
