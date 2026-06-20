#include <iostream>
#include <vector>
using namespace std;

// LeetCode 64 - Minimum Path Sum
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int i = 0;
        int j = 0;
        int sum = grid[0][0];

        // 錯誤想法：每一步都選右邊或下面比較小的那格
        // 但局部最小不一定會得到整體最小路徑。
        while (i != m - 1 || j != n - 1) {
            if (i == m - 1) {
                j++;
            } else if (j == n - 1) {
                i++;
            } else if (grid[i + 1][j] < grid[i][j + 1]) {
                i++;
            } else {
                j++;
            }

            sum += grid[i][j];
        }

        return sum;
    }
};
