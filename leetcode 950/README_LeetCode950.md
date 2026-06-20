# LeetCode 950 - Reveal Cards In Increasing Order

## 題目重點

這題給一疊牌 `deck`，我們要重新排列牌堆，使得按照題目的翻牌規則後，翻出來的牌會是由小到大。

翻牌規則是：

1. 翻開最上面的牌，拿出來。
2. 如果牌堆還有牌，就把下一張最上面的牌放到牌堆最下面。
3. 重複以上步驟，直到牌都翻完。

題目要回傳的是「一開始牌堆應該怎麼排」，不是翻牌後的結果。

例如：

```txt
Input: deck = [17,13,11,2,3,5,7]
Output: [2,13,3,11,5,17,7]
```

照這個順序翻牌，翻出來會是：

```txt
2, 3, 5, 7, 11, 13, 17
```

這樣就是遞增順序。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 950 - Reveal Cards In Increasing Order
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // 錯誤想法：直接把牌由小到大排序後回傳
        // 但題目要的是「原本牌堆的排列」，不是翻出來後的順序。
        sort(deck.begin(), deck.end());

        return deck;
    }
};
```

---

## 錯誤原因

錯誤程式碼直接把 `deck` 排序後回傳。

但是題目不是要回傳翻出來的順序，而是要回傳一開始牌堆的排列。

例如：

```txt
deck = [17,13,11,2,3,5,7]
```

如果直接排序，會得到：

```txt
[2,3,5,7,11,13,17]
```

但如果用這個當作一開始的牌堆去翻，翻牌過程不會得到同樣的遞增順序。

因為中間還有一個動作：

```txt
把下一張牌移到牌堆最下面
```

這個動作會改變後面牌出現的順序，所以不能只是單純排序。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// LeetCode 950 - Reveal Cards In Increasing Order
// Correct version

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.begin(), deck.end());

        queue<int> q;
        vector<int> ans(n);

        // 先把所有位置放進 queue
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        // 從小到大安排每張牌應該放在哪個位置
        for (int card : deck) {
            int index = q.front();
            q.pop();

            ans[index] = card;

            // 模擬題目中「把下一張牌放到牌堆底部」的動作
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return ans;
    }
};
```

---

## 解題想法

這題可以反過來想：既然翻出來要是由小到大，那就先把 `deck` 排序。

接著不要直接把排序後的牌拿來當答案，而是要模擬「哪些位置會被依序翻開」。

例如有 `n` 張牌，一開始位置是：

```txt
0, 1, 2, 3, ...
```

用 queue 存這些 index。

每次流程是：

1. queue 最前面的 index，就是下一張會被翻開的位置。
2. 把目前最小的牌放到這個位置。
3. 接著模擬題目規則，把下一個 index 移到 queue 最後面。
4. 繼續處理下一張比較大的牌。

這樣最後排好的 `ans`，按照題目翻牌規則翻出來，就會剛好是遞增順序。

---

## 心得

這題容易搞混「答案順序」和「翻出來的順序」。

一開始會想說把牌排序就好，但排序後只是想要翻出來的結果，不是一開始牌堆的排列。  
真正要做的是模擬翻牌時 index 出現的順序，再把小牌依序放到那些位置。

這題讓我更熟悉 queue 的用途，尤其是像這種一直把前面的東西移到後面的模擬題。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
