# LeetCode 56 - Merge Intervals

## 題目重點

這題會給很多個區間 `intervals`。

每個區間長這樣：

```txt
[start, end]
```

題目要把有重疊的區間合併起來。

例如：

```txt
intervals = [[1,3],[2,6],[8,10],[15,18]]
```

因為：

```txt
[1,3] 和 [2,6] 有重疊
```

所以要合併成：

```txt
[1,6]
```

最後答案是：

```txt
[[1,6],[8,10],[15,18]]
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 56 - Merge Intervals
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 蠢錯誤：完全沒有合併區間
        // 題目要把重疊的 interval 合起來，不是直接原樣回傳。
        return intervals;
    }
};
```

---

## 錯誤原因

這個錯誤版本完全沒有處理題目的重點。

它只是直接回傳原本的：

```cpp
intervals
```

可是題目要的是合併重疊區間。

例如：

```txt
intervals = [[1,3],[2,6]]
```

錯誤程式碼會回傳：

```txt
[[1,3],[2,6]]
```

但是這兩段其實有重疊，正確應該要變成：

```txt
[[1,6]]
```

所以錯誤原因很明顯：  
它沒有排序，也沒有判斷兩個區間有沒有重疊，更沒有合併。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 56 - Merge Intervals
// AC version

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        if(intervals.size() == 0){
            return ans;
        }

        // 先照起點由小到大排序
        sort(intervals.begin(), intervals.end());

        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++){
            int currentStart = intervals[i][0];
            int currentEnd = intervals[i][1];

            int lastEnd = ans.back()[1];

            // 如果目前區間的起點 <= 前一段的終點，代表有重疊
            if(currentStart <= lastEnd){
                ans.back()[1] = max(ans.back()[1], currentEnd);
            } else {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};
```

---

## 解題想法

這題可以先把所有區間排序。

排序後，區間會照起點由小到大排好。  
這樣我們只要一直看目前這段能不能跟答案裡最後一段合併。

先把第一個區間放進答案：

```cpp
ans.push_back(intervals[0]);
```

接著從第二個區間開始看。

假設目前區間是：

```txt
[currentStart, currentEnd]
```

答案最後一段是：

```txt
[某個 start, lastEnd]
```

如果：

```cpp
currentStart <= lastEnd
```

代表兩段有重疊，所以要合併。

合併時，終點要取比較大的那個：

```cpp
ans.back()[1] = max(ans.back()[1], currentEnd);
```

如果：

```cpp
currentStart > lastEnd
```

代表沒有重疊，就直接把目前區間放進答案。

---

## 心得

這題一開始如果直接看全部 interval，會覺得很亂。

但先排序後就簡單很多，因為只需要跟答案最後一段比較。  
我覺得這題重點是要看懂什麼叫重疊：

```txt
目前起點 <= 前一段終點
```

這樣就代表可以合併。

這題也是 interval 題很常見的基本寫法，之後遇到區間合併類題目應該都可以先想到排序。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
