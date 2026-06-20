# LeetCode 62 - Unique Paths

## 題目重點

這題給一個 `m x n` 的格子，機器人一開始在左上角，要走到右下角。

機器人每次只能往兩個方向走：

```txt
往右
往下
```

題目要問總共有幾種不同走法。

例如：

```txt
Input: m = 3, n = 7
Output: 28
```

因為從左上角走到右下角，有 28 種不同路徑。

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 62 - Unique Paths
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int uniquePaths(int m, int n) {
        // 錯誤想法：每一步都有「往右」或「往下」兩種選擇
        // 所以直接回傳 2 的步數次方。
        int steps = (m - 1) + (n - 1);
        int ans = 1;

        for (int i = 0; i < steps; i++) {
            ans *= 2;
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼以為每一步都有兩種選擇，所以用：

```txt
2 ^ steps
```

來算答案。

但是實際上不是每一步都能自由選「右」或「下」。  
因為最後一定要剛好走到右下角，所以往右的次數和往下的次數是固定的。

例如 `m = 3, n = 2`：

從左上角到右下角，一定要：

```txt
往下 2 次
往右 1 次
```

所以只有這幾種：

```txt
DDR
DRD
RDD
```

答案是 `3`。

可是錯誤程式碼會算：

```txt
steps = 3
2^3 = 8
```

這明顯太多，因為有些路徑會走出格子或不會剛好到終點。

---

## 正確程式碼

```cpp
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
```

---

## 解題想法

這題可以用動態規劃。

設：

```txt
dp[i][j] = 走到第 i 列第 j 欄的方法數
```

因為機器人只能往右或往下走，所以要走到某一格，只可能從兩個方向來：

```txt
從上面來
從左邊來
```

所以狀態轉移是：

```cpp
dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
```

第一列比較特別，因為只能一直往右走，所以每格都是 1 種方法。  
第一欄也一樣，只能一直往下走，所以每格也是 1 種方法。

最後答案就是：

```cpp
dp[m - 1][n - 1]
```

---

## 心得

這題是很基本的 DP 題。

一開始容易誤會成每一步都有兩種選擇，但其實路徑必須剛好到終點，所以不能亂走。  
用 `dp[i][j]` 來表示走到每一格的方法數，想法會比較清楚。

這題讓我練習到二維 DP，也比較理解「目前格子的答案可以由前面的狀態推過來」。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
