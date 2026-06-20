# LeetCode 64 - Minimum Path Sum

## 題目重點

這題給一個 `m x n` 的格子 `grid`，每一格都有一個非負整數。

從左上角出發，要走到右下角。  
每次只能往：

```txt
右邊
下面
```

題目要找出路徑上的數字總和最小是多少。

例如：

```txt
grid = [
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
```

最小路徑是：

```txt
1 -> 3 -> 1 -> 1 -> 1
```

所以答案是：

```txt
7
```

---

## 錯誤程式碼

```cpp
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
```

---

## 錯誤原因

錯誤程式碼使用貪心法，每一步都選右邊或下面比較小的格子。

可是這題不能只看眼前哪一格比較小。  
因為現在選比較小的格子，後面可能會遇到很大的數字，反而讓總和變大。

例如：

```txt
grid = [
  [1, 2, 100],
  [2, 100, 1],
  [1, 1, 1]
]
```

如果只看下一步比較小，可能會選到看起來比較好的方向，但後面不一定是整體最佳。

這題要考慮「走到每一格的最小成本」，不能只用局部判斷。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 64 - Minimum Path Sum
// Correct version

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        // 第一欄只能從上面往下走
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // 第一列只能從左邊往右走
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // 其他格子可以從上面或左邊來，取比較小的路徑
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};
```

---

## 解題想法

這題可以用動態規劃。

設：

```txt
dp[i][j] = 從左上角走到 grid[i][j] 的最小路徑總和
```

因為只能往右或往下走，所以走到某一格時，只可能從兩個地方來：

```txt
上面
左邊
```

所以狀態轉移是：

```cpp
dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
```

第一格就是：

```cpp
dp[0][0] = grid[0][0];
```

第一列只能從左邊一路走過來。  
第一欄只能從上面一路走下來。

最後答案就是右下角：

```cpp
dp[m - 1][n - 1]
```

---

## 心得

這題跟 LeetCode 62 有點像，都是格子 DP。

不同的是 LeetCode 62 是算路徑數量，這題是算最小路徑總和。  
一開始如果用貪心法，只看下一格哪個比較小，會忽略後面的情況。

這題讓我更理解 DP 的想法：不要只看眼前，而是記錄走到每一格目前可以得到的最佳結果。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
