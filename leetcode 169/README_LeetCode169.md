# LeetCode 169 - Majority Element

## 題目重點

這題給一個整數陣列 `nums`，要找出其中的 majority element。

majority element 的定義是：

```txt
出現次數大於 n / 2 的元素
```

題目保證這個元素一定存在。

例如：

```txt
Input: nums = [3,2,3]
Output: 3
```

因為 `3` 出現 2 次，超過陣列長度 3 的一半。

再例如：

```txt
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

因為 `2` 出現 4 次，超過陣列長度 7 的一半。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 169 - Majority Element
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 錯誤想法：直接回傳第一個數字
        // 但出現超過一半的數字不一定在第一個位置。
        return nums[0];
    }
};
```

---

## 錯誤原因

錯誤程式碼直接回傳 `nums[0]`，但 majority element 不一定出現在第一個位置。

例如：

```txt
Input: nums = [1,2,2,2,3]
Wrong Output: 1
Correct Output: 2
```

雖然 `1` 是第一個元素，但是它只出現一次。真正出現超過一半的是 `2`。

所以不能只看第一個元素，必須根據出現次數來判斷。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 169 - Majority Element
// Correct version

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;

        // Boyer-Moore Voting Algorithm
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
    }
};
```

---

## 解題想法

這題可以用 Boyer-Moore Voting Algorithm。

因為題目保證 majority element 一定存在，而且它的出現次數大於一半，所以可以用「抵消」的概念處理。

做法如下：

1. 用 `candidate` 紀錄目前可能的答案。
2. 用 `count` 紀錄目前候選人的票數。
3. 如果 `count == 0`，就把目前數字設成新的候選人。
4. 如果目前數字等於 `candidate`，就讓 `count++`。
5. 如果目前數字不等於 `candidate`，就讓 `count--`。
6. 最後留下的 `candidate` 就是 majority element。

---

## 心得

這題如果用暴力法計算每個數字出現幾次也可以做，但是比較麻煩。

Boyer-Moore Voting Algorithm 的想法很特別，它不是直接統計所有次數，而是利用 majority element 出現次數超過一半的特性，把不同的數字互相抵消。

這題讓我學到，當題目保證某個元素出現次數超過一半時，可以用更有效率的方法解決，而不一定要用雙層迴圈或 map。
