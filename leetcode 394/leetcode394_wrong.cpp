#include <iostream>
#include <string>
using namespace std;

// LeetCode 394 - Decode String
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    string decodeString(string s) {
        string ans = "";

        // 錯誤想法：遇到數字就只重複下一個字元
        // 但題目中的括號裡可能是一整段字串，也可能有巢狀結構。
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int times = s[i] - '0';

                if (i + 2 < s.length()) {
                    char c = s[i + 2];

                    for (int j = 0; j < times; j++) {
                        ans += c;
                    }
                }
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            }
        }

        return ans;
    }
};
