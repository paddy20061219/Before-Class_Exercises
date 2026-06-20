#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1109 - Corporate Flight Bookings
// Correct version

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        // 使用差分陣列處理區間加法
        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];

            diff[first - 1] += seats;

            if (last < n) {
                diff[last] -= seats;
            }
        }

        vector<int> ans(n, 0);
        ans[0] = diff[0];

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + diff[i];
        }

        return ans;
    }
};
