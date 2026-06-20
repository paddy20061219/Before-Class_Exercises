#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1700 - Number of Students Unable to Eat Lunch
// Correct version

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};

        // 統計喜歡圓形和方形三明治的學生人數
        for (int s : students) {
            count[s]++;
        }

        int remaining = students.size();

        // 依照三明治堆疊順序處理
        for (int sandwich : sandwiches) {
            if (count[sandwich] == 0) {
                return remaining;
            }

            count[sandwich]--;
            remaining--;
        }

        return 0;
    }
};
