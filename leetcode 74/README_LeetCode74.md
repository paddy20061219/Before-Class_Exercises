# LeetCode 74 - Search a 2D Matrix

## 題目重點

這題給一個 `m x n` 的二維矩陣 `matrix`，以及一個目標值 `target`。

矩陣有兩個重要特性：

1. 每一列的數字都由小到大排序。
2. 每一列的第一個數字都大於前一列的最後一個數字。

因此整個矩陣其實可以看成是一個排序好的一維陣列。

題目要求判斷 `target` 是否存在於矩陣中：

- 如果存在，回傳 `true`
- 如果不存在，回傳 `false`

例如：

```txt
Input:
matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
target = 3

Output: true
```

再例如：

```txt
target = 13

Output: false
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 74 - Search a 2D Matrix
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 錯誤想法：只搜尋第一列
        // 但 target 可能出現在其他列。
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == target) {
                return true;
            }
        }

        return false;
    }
};
```

---

## 錯誤原因

錯誤程式碼只檢查矩陣的第一列。

但是題目要求搜尋整個矩陣，`target` 可能出現在第二列、第三列或其他列。

例如：

```txt
matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
target = 16
```

錯誤程式碼只會搜尋第一列：

```txt
1, 3, 5, 7
```

因為第一列沒有 `16`，所以會回傳 `false`。

但正確答案應該是：

```txt
true
```

因為 `16` 出現在第二列。

所以這個做法沒有完整搜尋整個矩陣，會漏掉答案。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 74 - Search a 2D Matrix
// Correct version

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;

        // 把二維矩陣想成一個排序好的一維陣列來做 binary search
        while (left <= right) {
            int mid = left + (right - left) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};
```

---

## 解題想法

因為題目保證：

```txt
每一列由小到大排序
下一列第一個數字大於上一列最後一個數字
```

所以整個矩陣可以想成一個排序好的一維陣列。

例如：

```txt
1   3   5   7
10  11  16  20
23  30  34  60
```

可以看成：

```txt
1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 60
```

因此可以直接使用 binary search。

做法如下：

1. `m = matrix.size()`，代表列數。
2. `n = matrix[0].size()`，代表每列有幾個元素。
3. 設定搜尋範圍：
   - `left = 0`
   - `right = m * n - 1`
4. 每次取中間位置 `mid`。
5. 把一維 index 轉成二維位置：

```cpp
row = mid / n;
col = mid % n;
```

6. 如果 `matrix[row][col] == target`，回傳 `true`。
7. 如果目前數字小於 `target`，往右半邊找。
8. 如果目前數字大於 `target`，往左半邊找。
9. 如果搜尋結束都沒找到，回傳 `false`。

---

## 心得

這題的重點是看出二維矩陣其實可以當成一個排序好的一維陣列。

如果只用普通迴圈搜尋，雖然也可以找到答案，但沒有利用題目給的排序條件。  
使用 binary search 可以讓時間複雜度變成 `O(log(m * n))`。

這題讓我學到，遇到排序好的二維矩陣時，可以用 index 轉換的方式，把二維問題變成一維 binary search。
