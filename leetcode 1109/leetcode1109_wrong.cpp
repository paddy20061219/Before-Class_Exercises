#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1109 - Corporate Flight Bookings
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        // 錯誤想法：只把座位數加到起始航班
        // 但題目要求 first 到 last 之間的每一班都要加。
        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int seats = bookings[i][2];

            ans[first - 1] += seats;
        }

        return ans;
    }
};
