# LeetCode 70 - Climbing Stairs

## 題目重點

這題是爬樓梯問題。

一次可以爬：

```txt
1 階
或
2 階
```

題目給一個 `n`，代表總共有 `n` 階樓梯。

要問：

```txt
總共有幾種不同的方法可以爬到第 n 階
```

例如：

```txt
n = 2
```

可以有：

```txt
1 + 1
2
```

所以答案是：

```txt
2
```

如果：

```txt
n = 3
```

可以有：

```txt
1 + 1 + 1
1 + 2
2 + 1
```

所以答案是：

```txt
3
```

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 70 - Climbing Stairs
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int climbStairs(int n) {
        // 蠢錯誤：直接回傳 n
        // 題目要算方法數，不是樓梯有幾階就回傳幾。
        return n;
    }
};
```

---

## 錯誤原因

這個錯誤版本直接回傳：

```cpp
n
```

意思是它把「樓梯階數」當成「方法數」。

可是這兩個不是同一件事。

例如：

```txt
n = 4
```

錯誤程式碼會回傳：

```txt
4
```

但正確的方法其實有：

```txt
1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
```

所以正確答案是：

```txt
5
```

這題不是單純回傳階數，  
而是要算有幾種組合方式可以走到最後。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 70 - Climbing Stairs
// AC version

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }

        vector<int> dp(n + 1, 0);

        dp[1] = 1;
        dp[2] = 2;

        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
```

---

## 解題想法

這題可以用 DP。

先想最後一步怎麼來。

如果要到第 `i` 階，最後一步可能是：

```txt
從第 i - 1 階爬 1 階上來
或
從第 i - 2 階爬 2 階上來
```

所以到第 `i` 階的方法數就是：

```txt
到第 i - 1 階的方法數 + 到第 i - 2 階的方法數
```

也就是：

```cpp
dp[i] = dp[i - 1] + dp[i - 2];
```

先知道：

```txt
dp[1] = 1
dp[2] = 2
```

然後從第 3 階開始慢慢算到第 `n` 階。

最後答案就是：

```cpp
dp[n]
```

---

## 心得

這題看起來很簡單，但不能直接回傳 `n`。

因為題目不是問樓梯有幾階，  
而是問走法有幾種。

我覺得這題很適合拿來練 DP 的第一題。  
只要想懂「最後一步可能從哪裡來」，就可以推出公式：

```txt
dp[i] = dp[i - 1] + dp[i - 2]
```

其實它也很像 Fibonacci 數列。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
