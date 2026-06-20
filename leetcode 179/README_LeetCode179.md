# LeetCode 179 - Largest Number

## 題目重點

這題給一個非負整數陣列 `nums`，要把這些數字重新排列，讓它們接起來後形成最大的數字。

因為答案可能很大，所以要用 `string` 回傳，不是用 `int` 或 `long long`。

例如：

```txt
Input: nums = [10,2]
Output: "210"
```

因為 `2` 放在 `10` 前面會得到比較大的數字：

```txt
210 > 102
```

再例如：

```txt
Input: nums = [3,30,34,5,9]
Output: "9534330"
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 179 - Largest Number
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // 錯誤想法：直接用字串由大到小排序
        // 但這樣不能保證接起來後是最大的數字。
        sort(arr.rbegin(), arr.rend());

        string ans = "";
        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼只是把數字轉成字串後，直接用字典序由大到小排序。

但是這題不是單純比較哪個字串比較大，而是要比較兩個數字誰放前面會讓整體結果比較大。

例如：

```txt
Input: nums = [3,30,34,5,9]
```

錯誤程式碼可能會排成：

```txt
9, 5, 34, 30, 3
```

接起來得到：

```txt
9534303
```

但是正確排列應該是：

```txt
9, 5, 34, 3, 30
```

接起來得到：

```txt
9534330
```

因為比較 `3` 和 `30` 時，不能只看字典序，而是要比較：

```txt
"3" + "30" = "330"
"30" + "3" = "303"
```

`330` 比 `303` 大，所以 `3` 應該排在 `30` 前面。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// LeetCode 179 - Largest Number
// Correct version

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int num : nums) {
            arr.push_back(to_string(num));
        }

        // 如果 a + b 比 b + a 大，代表 a 應該排在 b 前面
        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        // 處理全部都是 0 的情況
        if (arr[0] == "0") {
            return "0";
        }

        string ans = "";
        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};
```

---

## 解題想法

這題的核心是自訂排序規則。

對於兩個字串 `a` 和 `b`，要判斷誰應該放前面，不是比較 `a > b`，而是比較：

```txt
a + b
b + a
```

如果：

```txt
a + b > b + a
```

代表 `a` 放前面會得到比較大的結果。

例如：

```txt
a = "3"
b = "30"
```

比較：

```txt
"330" 和 "303"
```

因為 `"330"` 比 `"303"` 大，所以 `"3"` 要排在 `"30"` 前面。

做法如下：

1. 把所有整數轉成字串。
2. 使用自訂排序規則 `a + b > b + a`。
3. 排序後把所有字串接起來。
4. 如果排序後第一個字串是 `"0"`，代表全部都是 0，直接回傳 `"0"`。

---

## 心得

這題看起來像是排序題，但不能用普通的數字排序或字串排序。

真正的關鍵是比較兩個數字「誰放前面比較好」。  
用 `a + b > b + a` 這個規則就能決定排列順序。

這題讓我學到，自訂排序不一定是比較單一元素大小，有時候要根據題目的目標來設計比較條件。
