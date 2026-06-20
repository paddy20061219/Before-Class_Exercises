# LeetCode 724 - Find Pivot Index

## 題目重點

這題給一個整數陣列 `nums`，要找出 pivot index。

pivot index 的定義是：

```txt
某個位置左邊所有數字的總和 = 右邊所有數字的總和
```

注意：

1. 左邊總和不包含目前位置的數字。
2. 右邊總和也不包含目前位置的數字。
3. 如果有多個 pivot index，要回傳最左邊的那一個。
4. 如果不存在 pivot index，就回傳 `-1`。

例如：

```txt
Input: nums = [1,7,3,6,5,6]
Output: 3
```

因為 index `3` 的數字是 `6`，它左邊的總和是：

```txt
1 + 7 + 3 = 11
```

右邊的總和是：

```txt
5 + 6 = 11
```

所以 pivot index 是 `3`。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 724 - Find Pivot Index
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        // 錯誤想法：只要左邊總和等於右邊總和就回傳
        // 但是這裡把目前 nums[i] 也算進右邊，導致判斷錯誤。
        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int rightSum = total - leftSum;

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
```

---

## 錯誤原因

錯誤程式碼在計算右邊總和時寫成：

```cpp
int rightSum = total - leftSum;
```

但是這樣會把目前位置 `nums[i]` 也算進右邊總和。

題目規定 pivot index 的左右總和都不能包含目前位置的數字，所以正確的右邊總和應該是：

```cpp
int rightSum = total - leftSum - nums[i];
```

例如：

```txt
Input: nums = [1,7,3,6,5,6]
Correct Output: 3
```

當 `i = 3` 時：

```txt
leftSum = 1 + 7 + 3 = 11
nums[i] = 6
rightSum = 5 + 6 = 11
```

但錯誤程式碼會算成：

```txt
rightSum = total - leftSum = 28 - 11 = 17
```

它把目前的 `6` 也算進去了，所以判斷會錯。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 724 - Find Pivot Index
// Correct version

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int leftSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            // 右邊總和不能包含目前 nums[i]
            int rightSum = total - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }

        return -1;
    }
};
```

---

## 解題想法

這題可以用前綴和概念解。

先算出整個陣列的總和 `total`。  
接著從左到右掃描陣列，並用 `leftSum` 紀錄目前 index 左邊所有數字的總和。

對於每個位置 `i`：

```txt
右邊總和 = total - leftSum - nums[i]
```

因為 `total` 包含全部數字，所以要扣掉左邊總和，也要扣掉目前位置的數字。

如果：

```txt
leftSum == rightSum
```

代表目前位置就是 pivot index，直接回傳 `i`。

如果不是，就把 `nums[i]` 加到 `leftSum`，繼續檢查下一個位置。

---

## 心得

這題的重點是目前位置的數字不能算進左邊，也不能算進右邊。

如果計算右邊總和時忘記扣掉 `nums[i]`，就會導致判斷錯誤。  
用 `total` 搭配 `leftSum` 可以讓每個位置都用 `O(1)` 的時間判斷，因此整體只需要掃描一次陣列。

這題讓我學到，前綴和題目要特別注意目前位置是否要被包含進計算。
