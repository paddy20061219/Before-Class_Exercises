#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1700 - Number of Students Unable to Eat Lunch
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int unable = 0;

        // 錯誤想法：直接比較同一個位置的學生和三明治
        // 但題目中的學生可以排到隊伍後面，不是只看原本 index。
        for (int i = 0; i < students.size(); i++) {
            if (students[i] != sandwiches[i]) {
                unable++;
            }
        }

        return unable;
    }
};
