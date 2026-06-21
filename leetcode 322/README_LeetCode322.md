# LeetCode 322 - Coin Change

## 題目重點

這題會給一堆硬幣面額：

```txt
coins
```

還有一個目標金額：

```txt
amount
```

題目要問：

```txt
湊出 amount 最少需要幾枚硬幣
```

每種硬幣可以使用很多次。

如果沒辦法剛好湊出 `amount`，就回傳：

```txt
-1
```

例如：

```txt
coins = [1,2,5]
amount = 11
```

可以這樣湊：

```txt
5 + 5 + 1
```

總共用了 3 枚硬幣，所以答案是：

```txt
3
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 322 - Coin Change
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 蠢錯誤：直接回傳 amount
        // 題目要的是最少硬幣數，不是金額是多少。
        return amount;
    }
};
```

---

## 錯誤原因

這個錯誤版本直接回傳：

```cpp
amount
```

意思是它把「金額」當成「硬幣數量」。

可是題目要的是最少硬幣數。

例如：

```txt
coins = [1,2,5]
amount = 11
```

錯誤程式碼會回傳：

```txt
11
```

但其實可以用：

```txt
5 + 5 + 1
```

只要 3 枚硬幣。

正確答案應該是：

```txt
3
```

所以這個錯誤很明顯就是沒有真的去湊錢，也沒有找最少硬幣數。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 322 - Coin Change
// AC version

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;

        for(int money = 1; money <= amount; money++){
            for(int i = 0; i < coins.size(); i++){
                int coin = coins[i];

                if(money - coin >= 0){
                    dp[money] = min(dp[money], dp[money - coin] + 1);
                }
            }
        }

        if(dp[amount] == amount + 1){
            return -1;
        }

        return dp[amount];
    }
};
```

---

## 解題想法

這題可以用 DP。

先設：

```txt
dp[money] = 湊出 money 這個金額，最少需要幾枚硬幣
```

例如：

```txt
dp[0] = 0
```

因為湊出 0 元不需要任何硬幣。

一開始先把其他值設很大：

```cpp
vector<int> dp(amount + 1, amount + 1);
```

`amount + 1` 可以當成一個很大的數字，代表目前還湊不出來。

接著從 `1` 元一路算到 `amount`。

對每個金額 `money`，試試看每一種硬幣 `coin`。

如果：

```cpp
money - coin >= 0
```

代表這枚硬幣可以用。

那湊出 `money` 的方法可能是：

```txt
先湊出 money - coin
再加上 1 枚 coin
```

所以可以寫成：

```cpp
dp[money] = min(dp[money], dp[money - coin] + 1);
```

最後如果 `dp[amount]` 還是很大的數字，代表湊不出來，回傳 `-1`。  
不然就回傳 `dp[amount]`。

---

## 心得

這題一開始會想直接用最大的硬幣一直拿，  
可是那樣不一定會得到最少硬幣數。

所以用 DP 比較穩。

我覺得這題重點是要看懂：

```txt
dp[money] 是湊出 money 的最少硬幣數
```

然後每次都從前面已經算好的小金額推到比較大的金額。

這題也是很經典的 DP 題，剛開始可能會覺得有點抽象，  
但把 `dp[0] = 0` 和 `dp[money - coin] + 1` 想清楚就比較懂了。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
