#include <iostream>
#include <vector>
using namespace std;

// LeetCode 62 - Unique Paths
// Correct version

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // 第一欄只能一直往下走，所以只有 1 種走法
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }

        // 第一列只能一直往右走，所以只有 1 種走法
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // 其他格子的走法 = 從上面來 + 從左邊來
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
