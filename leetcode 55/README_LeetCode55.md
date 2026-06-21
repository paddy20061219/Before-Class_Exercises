# LeetCode 55 - Jump Game

## 題目重點

這題會給一個陣列 `nums`。

每個位置的數字代表：

```txt
從這個位置最多可以往右跳幾步
```

一開始站在 index `0`。

題目要問：

```txt
能不能跳到最後一格
```

如果可以，就回傳：

```txt
true
```

如果不行，就回傳：

```txt
false
```

例如：

```txt
nums = [2,3,1,1,4]
```

可以這樣跳：

```txt
index 0 -> index 1 -> index 4
```

所以答案是：

```txt
true
```

但是：

```txt
nums = [3,2,1,0,4]
```

會卡在 `0` 那格，沒辦法跳到最後的 `4`。

所以答案是：

```txt
false
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 55 - Jump Game
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 蠢錯誤：完全不檢查能不能跳到最後
        // 直接說一定可以，遇到卡住的測資就會錯。
        return true;
    }
};
```

---

## 錯誤原因

這個錯誤版本直接回傳：

```cpp
true
```

意思是它覺得每個測資都一定可以跳到最後。

可是題目不一定都可以。

例如：

```txt
nums = [3,2,1,0,4]
```

從 index `0` 最多可以跳 3 步。  
可是跳到後面會發現一定會被卡在 index `3`。

因為：

```txt
nums[3] = 0
```

站在這裡就不能再往前跳。

所以正確答案應該是：

```txt
false
```

但錯誤程式碼一定回傳：

```txt
true
```

所以很明顯錯了。

這題一定要真的判斷目前最多可以跳到哪裡，不能直接亂回傳。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 55 - Jump Game
// AC version

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;

        for(int i = 0; i < nums.size(); i++){

            // 如果現在的位置 i 已經超過目前能到的最遠位置
            // 代表根本走不到這裡
            if(i > farthest){
                return false;
            }

            farthest = max(farthest, i + nums[i]);

            if(farthest >= nums.size() - 1){
                return true;
            }
        }

        return true;
    }
};
```

---

## 解題想法

這題可以用貪心法。

我們用一個變數：

```cpp
int farthest = 0;
```

它代表：

```txt
目前最多可以跳到哪個 index
```

一開始站在 index `0`，所以最遠先設成 `0`。

接著從左到右檢查每個位置。

如果現在的位置是 `i`，但：

```cpp
i > farthest
```

代表目前根本跳不到 index `i`。

既然連 `i` 都到不了，後面也不用看了，直接回傳：

```cpp
false
```

如果可以到 `i`，就用這個位置更新最遠距離：

```cpp
farthest = max(farthest, i + nums[i]);
```

意思是：

```txt
從 i 這格，最多可以跳到 i + nums[i]
```

如果某一次發現：

```cpp
farthest >= nums.size() - 1
```

代表已經可以跳到最後一格，所以回傳：

```cpp
true
```

---

## 心得

這題一開始可能會想要真的模擬怎麼跳，  
但其實不用知道每一步到底跳去哪裡。

只要知道目前「最遠可以到哪裡」就好。

我覺得這題最重要的是這句：

```txt
如果 i > farthest，代表目前位置走不到
```

只要有一格走不到，就代表後面也不用繼續了。

這題是 greedy 題裡蠻基本的一題，但剛開始看可能會覺得有點抽象，要多想一下 `farthest` 的意思。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
