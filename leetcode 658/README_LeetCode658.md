# LeetCode 658 - Find K Closest Elements

## 題目重點

這題給一個已經由小到大排序好的整數陣列 `arr`，還有兩個整數 `k` 和 `x`。

目標是找出陣列中最接近 `x` 的 `k` 個數字，並且答案也要由小到大排序。

判斷誰比較接近 `x` 的規則是：

```txt
|a - x| < |b - x|
```

如果距離一樣，數字比較小的優先。

例如：

```txt
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```

因為最接近 `3` 的四個數字是 `1, 2, 3, 4`。

再例如：

```txt
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
```

因為 `x = -1` 比所有數字都小，所以最接近的就是最前面的四個數字。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 658 - Find K Closest Elements
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;

        // 錯誤想法：直接回傳前 k 個元素
        // 但前 k 個元素不一定是最接近 x 的元素。
        for (int i = 0; i < k && i < arr.size(); i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼直接回傳陣列前 `k` 個元素。

但是題目要找的是最接近 `x` 的 `k` 個元素，不一定在陣列最前面。

例如：

```txt
Input: arr = [1,2,3,4,5], k = 4, x = 5
Wrong Output: [1,2,3,4]
Correct Output: [2,3,4,5]
```

因為 `5` 本身最接近 `x = 5`，所以答案應該包含 `5`。

錯誤程式碼完全沒有比較元素和 `x` 的距離，所以不能正確解題。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 658 - Find K Closest Elements
// Correct version

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;

        // 二分搜尋最佳的連續區間起點
        while (left < right) {
            int mid = left + (right - left) / 2;

            // 比較 x 距離左邊 arr[mid] 和右邊 arr[mid + k] 哪邊比較遠
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        vector<int> ans;
        for (int i = left; i < left + k; i++) {
            ans.push_back(arr[i]);
        }

        return ans;
    }
};
```

---

## 解題想法

因為 `arr` 已經排序好，所以最後答案一定會是陣列中的一段連續區間。

因此問題可以變成：

```txt
找出長度為 k 的最佳連續區間
```

我們可以用二分搜尋找這個區間的起點。

假設目前檢查的起點是 `mid`，那麼候選區間是：

```txt
arr[mid] 到 arr[mid + k - 1]
```

接著比較區間外左右兩端：

```txt
arr[mid]
arr[mid + k]
```

如果：

```txt
x - arr[mid] > arr[mid + k] - x
```

代表左邊的 `arr[mid]` 離 `x` 比右邊的 `arr[mid + k]` 更遠，所以最佳區間應該往右移。

否則就保留左邊，讓右界往左縮。

最後 `left` 就會是最佳區間的起點，取出 `left` 到 `left + k - 1` 就是答案。

---

## 心得

這題的重點是理解答案在排序陣列中會是一段連續區間。

一開始如果只拿前 `k` 個元素，完全沒有根據 `x` 判斷距離，所以一定會錯。  
用二分搜尋可以快速找到最好的區間起點，比暴力比較每個元素更有效率。

這題讓我練習到排序陣列中的區間判斷，也學到可以用二分搜尋找最佳答案的位置。
