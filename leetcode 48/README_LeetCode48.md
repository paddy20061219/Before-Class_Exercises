# LeetCode 48 - Rotate Image

## 題目重點

這題給一個 `n x n` 的二維矩陣，要將矩陣原地順時針旋轉 90 度。

題目要求：

1. 不能另外建立一個新的矩陣來存答案。
2. 必須直接修改原本的 `matrix`。
3. 旋轉方向是順時針 90 度。

例如：

```txt
Input:
1 2 3
4 5 6
7 8 9
```

旋轉後變成：

```txt
7 4 1
8 5 2
9 6 3
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 48 - Rotate Image
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 錯誤想法：只做矩陣轉置
        // 但題目要求的是順時針旋轉 90 度，不是單純轉置。
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
```

---

## 錯誤原因

錯誤程式碼只做了矩陣轉置，也就是把 `matrix[i][j]` 和 `matrix[j][i]` 交換。

例如：

```txt
Input:
1 2 3
4 5 6
7 8 9
```

只做轉置會變成：

```txt
1 4 7
2 5 8
3 6 9
```

但是題目要的是順時針旋轉 90 度：

```txt
7 4 1
8 5 2
9 6 3
```

所以只做轉置是不夠的，還需要把每一列反轉。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 48 - Rotate Image
// Correct version

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 1. 先做矩陣轉置
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. 再把每一列反轉
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

---

## 解題想法

順時針旋轉 90 度可以拆成兩個步驟：

### 第一步：矩陣轉置

把矩陣的行和列互換。

原本：

```txt
1 2 3
4 5 6
7 8 9
```

轉置後：

```txt
1 4 7
2 5 8
3 6 9
```

### 第二步：反轉每一列

把每一列左右反轉。

```txt
1 4 7      7 4 1
2 5 8  ->  8 5 2
3 6 9      9 6 3
```

這樣就完成順時針旋轉 90 度。

---

## 心得

這題的重點是理解矩陣旋轉可以拆成簡單操作。

一開始如果只做轉置，結果會像是沿著主對角線翻轉，而不是旋轉。  
正確做法是先轉置，再反轉每一列。

這題讓我練習到二維陣列的操作，也讓我知道很多矩陣旋轉題可以透過「轉置」和「反轉」來解。
