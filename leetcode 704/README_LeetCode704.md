# LeetCode 704 - Binary Search

## 題目重點

這題給一個已經由小到大排序好的整數陣列 `nums`，以及一個目標值 `target`。

題目要求：

1. 如果 `target` 存在於 `nums` 中，回傳它的 index。
2. 如果 `target` 不存在，回傳 `-1`。
3. 必須使用時間複雜度 `O(log n)` 的演算法。
4. 因為陣列已排序，所以適合使用 binary search。

例如：

```txt
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
```

因為 `nums[4] = 9`。

再例如：

```txt
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
```

因為 `2` 不在陣列中。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 704 - Binary Search
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // 錯誤寫法：while 條件少了等於，會漏掉 left == right 的情況
        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
```

---

## 錯誤原因

錯誤程式碼的問題在於：

```cpp
while (left < right)
```

這個條件會漏掉 `left == right` 的情況。

在 binary search 裡，當搜尋範圍縮小到只剩一個元素時，`left` 會等於 `right`。  
這個位置仍然需要被檢查，否則可能會錯過答案。

例如：

```txt
Input: nums = [5], target = 5
Wrong Output: -1
Correct Output: 0
```

因為一開始：

```txt
left = 0
right = 0
```

但 `left < right` 不成立，所以迴圈不會執行，程式直接回傳 `-1`。

再例如：

```txt
Input: nums = [1,3,5,7,9], target = 9
```

搜尋到最後可能只剩下 index `4` 還沒檢查，但如果條件是 `left < right`，就會提早停止。

所以正確條件應該是：

```cpp
while (left <= right)
```

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 704 - Binary Search
// Correct version

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};
```

---

## 解題想法

這題是標準 binary search。

因為陣列已經排序好，所以每次可以檢查中間位置 `mid`。

做法如下：

1. 設定 `left = 0`，`right = nums.size() - 1`。
2. 當 `left <= right` 時持續搜尋。
3. 計算中間位置：

```cpp
int mid = left + (right - left) / 2;
```

4. 如果 `nums[mid] == target`，直接回傳 `mid`。
5. 如果 `nums[mid] < target`，代表答案在右半邊，所以讓 `left = mid + 1`。
6. 如果 `nums[mid] > target`，代表答案在左半邊，所以讓 `right = mid - 1`。
7. 如果迴圈結束還沒找到，回傳 `-1`。

---

## 心得

這題是 binary search 的基本題，但很容易錯在邊界條件。

`while (left <= right)` 的意思是只要搜尋範圍還有元素，就要繼續檢查。  
如果寫成 `left < right`，就會漏掉最後一個可能的位置。

另外，計算 `mid` 時用：

```cpp
left + (right - left) / 2
```

比直接寫 `(left + right) / 2` 更安全，可以避免在數字很大時發生 overflow。

這題讓我學到 binary search 最重要的是邊界條件和指標更新，少一個等號就可能造成答案錯誤。
