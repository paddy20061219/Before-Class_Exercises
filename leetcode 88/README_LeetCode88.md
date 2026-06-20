# LeetCode 88 - Merge Sorted Array

## 題目重點

這題給兩個已排序的整數陣列 `nums1` 和 `nums2`。

其中：

```txt
nums1 的前 m 個元素是有效數字
nums2 的前 n 個元素是有效數字
nums1 的總長度是 m + n
nums1 後面多出來的空位是用來放 nums2 的
```

目標是把 `nums2` 合併進 `nums1`，讓 `nums1` 變成排序好的陣列。

題目要求直接修改 `nums1`，不需要回傳值。

例如：

```txt
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

Output:
nums1 = [1,2,2,3,5,6]
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 88 - Merge Sorted Array
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k = 0;

        // 錯誤想法：從前面開始合併，直接寫回 nums1
        // 但這樣會覆蓋 nums1 原本還沒使用到的數字。
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                nums1[k] = nums1[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }

        while (j < n) {
            nums1[k] = nums2[j];
            j++;
            k++;
        }
    }
};
```

---

## 錯誤原因

錯誤程式碼從前面開始把答案寫回 `nums1`。

問題是 `nums1` 前面的數字還沒有全部比較完，如果直接寫入，就可能把還沒用到的原始資料覆蓋掉。

例如：

```txt
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3
```

當程式比較到 `nums1[1] = 2` 和 `nums2[0] = 2` 時，可能會開始覆蓋 `nums1` 前面的內容。  
更嚴重的是，當 `nums2[j]` 比 `nums1[i]` 小時，會直接寫到 `nums1[k]`，導致 `nums1` 原本還沒比較到的值被破壞。

例如：

```txt
nums1 = [4,5,6,0,0,0]
nums2 = [1,2,3]
```

正確答案應該是：

```txt
[1,2,3,4,5,6]
```

但從前面寫回會把 `4,5,6` 覆蓋掉，造成答案錯誤。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 88 - Merge Sorted Array
// Correct version

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        // 從後面開始放，避免覆蓋 nums1 前面還沒比較的數字
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // 如果 nums2 還有剩，就補到 nums1 前面
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
```

---

## 解題想法

這題最重要的技巧是從後面開始合併。

因為 `nums1` 後面本來就是空位，所以從後面放數字不會破壞前面還沒比較的資料。

做法如下：

1. `i = m - 1`，指向 `nums1` 有效元素的最後一個。
2. `j = n - 1`，指向 `nums2` 的最後一個。
3. `k = m + n - 1`，指向 `nums1` 最後一格。
4. 比較 `nums1[i]` 和 `nums2[j]`，把比較大的放到 `nums1[k]`。
5. 放完後，對應指標往前移。
6. 如果 `nums2` 還有剩，就繼續補進 `nums1`。
7. 如果 `nums1` 還有剩，不用特別處理，因為它原本就已經在正確位置。

---

## 心得

這題看起來只是合併兩個排序陣列，但重點是要原地修改 `nums1`。

如果從前面開始合併，很容易覆蓋掉 `nums1` 原本還沒使用的元素。  
從後面開始合併就可以避開這個問題，因為後面的空位本來就是給合併結果使用的。

這題讓我學到，遇到原地修改陣列的題目時，要特別注意資料會不會被自己覆蓋。
