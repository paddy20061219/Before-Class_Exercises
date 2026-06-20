# LeetCode 414 - Third Maximum Number

## 題目重點

這題給一個整數陣列 `nums`，要找出「第三大的不重複數字」。

如果不存在第三大的不重複數字，就回傳最大值。

例如：

```txt
Input: nums = [3,2,1]
Output: 1
```

因為第三大的數字是 `1`。

再例如：

```txt
Input: nums = [1,2]
Output: 2
```

因為只有兩個不同的數字，不存在第三大，所以回傳最大值 `2`。

再例如：

```txt
Input: nums = [2,2,3,1]
Output: 1
```

因為不同的數字是：

```txt
3, 2, 1
```

第三大是 `1`。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 414 - Third Maximum Number
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // 錯誤想法：排序後直接回傳第三個數字
        // 但題目要求的是「第三大的不重複數字」。
        sort(nums.rbegin(), nums.rend());

        if (nums.size() >= 3) {
            return nums[2];
        }

        return nums[0];
    }
};
```

---

## 錯誤原因

錯誤程式碼把陣列由大到小排序後，直接回傳第三個位置的數字。

但是題目要求的是「第三大的不重複數字」，重複出現的數字不能重複計算。

例如：

```txt
Input: nums = [2,2,3,1]
```

排序後會變成：

```txt
[3,2,2,1]
```

錯誤程式碼會回傳第三個數字：

```txt
2
```

但是正確答案應該是：

```txt
1
```

因為不同的數字只有：

```txt
3, 2, 1
```

第三大是不重複的 `1`。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <set>
using namespace std;

// LeetCode 414 - Third Maximum Number
// Correct version

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;

        // set 會自動去除重複元素，並且保持排序
        for (int num : nums) {
            s.insert(num);
        }

        // 如果不同的數字少於 3 個，就回傳最大值
        if (s.size() < 3) {
            return *s.rbegin();
        }

        // 刪掉最大值
        s.erase(*s.rbegin());

        // 刪掉第二大值
        s.erase(*s.rbegin());

        // 現在最大的就是第三大值
        return *s.rbegin();
    }
};
```

---

## 解題想法

這題的重點是要找「不重複」的第三大數字。

可以使用 `set` 來處理，因為 `set` 有兩個特性：

```txt
1. 會自動去除重複元素
2. 會自動排序
```

做法如下：

1. 把 `nums` 裡的每個數字放進 `set`。
2. 如果 `set` 裡不同的數字少於 3 個，代表沒有第三大，直接回傳最大值。
3. 如果有至少 3 個不同數字，先刪掉最大值。
4. 再刪掉第二大值。
5. 此時 `set` 裡最大的數字，就是第三大值。

例如：

```txt
nums = [2,2,3,1]
```

放進 `set` 後會變成：

```txt
{1,2,3}
```

刪掉最大值 `3`，再刪掉第二大值 `2`，剩下最大值就是 `1`。

---

## 心得

這題容易錯在把「第三個數字」當成「第三大的不重複數字」。

如果陣列裡有重複值，直接排序後取第三個位置就會錯。  
使用 `set` 可以很方便地去除重複元素，也能快速找到最大值。

這題讓我學到，題目如果特別強調 distinct 或不重複，就不能只看原本陣列的位置，要先處理重複元素。
