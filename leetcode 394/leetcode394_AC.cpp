#include <iostream>
#include <string>
#include <stack>
using namespace std;

// LeetCode 394 - Decode String
// Correct version

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int number = 0;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                number = number * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(number);
                stringStack.push(current);

                number = 0;
                current = "";
            } else if (c == ']') {
                int times = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                string repeated = "";
                for (int i = 0; i < times; i++) {
                    repeated += current;
                }

                current = previous + repeated;
            } else {
                current += c;
            }
        }

        return current;
    }
};
