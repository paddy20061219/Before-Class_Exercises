# LeetCode 1046 - Last Stone Weight

## 題目重點

這題給一堆石頭，每顆石頭都有重量。

每次要選出最重的兩顆石頭來撞：

```txt
x = 最重的石頭
y = 第二重的石頭
```

而且 `x >= y`。

規則是：

1. 如果 `x == y`，兩顆石頭都消失。
2. 如果 `x != y`，比較小的那顆消失，比較大的那顆會剩下 `x - y` 的重量。
3. 重複這個動作，直到剩下 0 顆或 1 顆石頭。
4. 最後回傳剩下那顆石頭的重量，如果沒有石頭就回傳 `0`。

例如：

```txt
stones = [2,7,4,1,8,1]
```

大概過程：

```txt
8 和 7 撞，剩 1
4 和 2 撞，剩 2
2 和 1 撞，剩 1
1 和 1 撞，都消失
最後剩 1
```

所以答案是：

```txt
1
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1046 - Last Stone Weight
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // 蠢錯誤：直接回傳石頭數量
        // 題目要的是最後剩下的重量，不是剩幾顆石頭。
        return stones.size();
    }
};
```

---

## 錯誤原因

這個錯誤版本完全搞錯題目意思。

題目要回傳的是：

```txt
最後剩下石頭的重量
```

不是：

```txt
一開始有幾顆石頭
```

例如：

```txt
stones = [2,7,4,1,8,1]
```

錯誤程式碼會回傳：

```txt
6
```

因為陣列裡有 6 顆石頭。

可是正確答案是：

```txt
1
```

因為要一直選最重的兩顆石頭互撞，最後剩下的重量才是答案。

所以這題不能只看陣列大小，一定要照題目的撞石頭規則處理。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// LeetCode 1046 - Last Stone Weight
// AC version

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // 把所有石頭重量放進 max heap
        for(int stone : stones){
            pq.push(stone);
        }

        // 每次拿出最重的兩顆石頭互撞
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();

            int second = pq.top();
            pq.pop();

            if(first != second){
                pq.push(first - second);
            }
        }

        if(pq.empty()){
            return 0;
        }

        return pq.top();
    }
};
```

---

## 解題想法

這題每次都要拿出最重的兩顆石頭。

所以可以用：

```cpp
priority_queue<int>
```

它預設是 max heap，也就是最大的數字會在最上面。

流程是：

1. 先把所有石頭重量放進 `priority_queue`。
2. 當裡面還有超過 1 顆石頭時，就拿出最重的兩顆。
3. 如果兩顆一樣重，就不用放回去，因為兩顆都碎掉。
4. 如果不一樣重，就把差值 `first - second` 放回去。
5. 最後如果 queue 空了，回傳 `0`。
6. 如果還有一顆，回傳它的重量。

這樣就不用每次自己排序找最大值，`priority_queue` 會幫我們把最大值放在最前面。

---

## 心得

這題重點是每次都要找目前最重的兩顆石頭。

如果用普通陣列，每次都自己找最大值會比較麻煩。  
用 `priority_queue` 比較直覺，因為它每次 `top()` 都會拿到最大的石頭。

這題也讓我練習到 heap 的基本用法。  
我覺得要先記住：`priority_queue<int>` 預設就是大的在前面。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
