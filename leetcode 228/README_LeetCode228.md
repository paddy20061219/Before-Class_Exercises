# LeetCode 228 - Summary Ranges

## 題目重點

這題會給一個已經排序好的整數陣列 `nums`。

題目要把連續的數字整理成區間。

如果只有一個數字，就直接寫那個數字。  
如果是一段連續的數字，就寫成：

```txt
start->end
```

例如：

```txt
nums = [0,1,2,4,5,7]
```

可以分成：

```txt
0,1,2  是連續的
4,5    是連續的
7      只有自己
```

所以答案是：

```txt
["0->2","4->5","7"]
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LeetCode 228 - Summary Ranges
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        // 蠢錯誤：直接把每個數字都丟進答案
        // 題目要把連續的數字合併成範圍，不是全部分開。
        for(int i=0;i<nums.size();i++){
            ans.push_back(to_string(nums[i]));
        }

        return ans;
    }
};
```

---

## 錯誤原因

這個錯誤版本只是把每個數字都變成字串。

例如：

```txt
nums = [0,1,2,4,5,7]
```

錯誤程式碼會回傳：

```txt
["0","1","2","4","5","7"]
```

可是題目要把連續的數字合併。

正確答案應該是：

```txt
["0->2","4->5","7"]
```

所以這個錯誤很明顯就是沒有處理「連續範圍」。

這題不能只是看到一個數字就丟進答案，  
要先看它後面有沒有跟它連在一起。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// LeetCode 228 - Summary Ranges
// AC version

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();

        int i = 0;

        while(i < n){
            int start = nums[i];

            // 找這一段連續數字的最後一個
            while(i + 1 < n && (long long)nums[i] + 1 == nums[i + 1]){
                i++;
            }

            int end = nums[i];

            if(start == end){
                ans.push_back(to_string(start));
            } else {
                ans.push_back(to_string(start) + "->" + to_string(end));
            }

            i++;
        }

        return ans;
    }
};
```

---

## 解題想法

這題可以用一個 index 慢慢往右掃。

先把目前數字當成一段範圍的開始：

```cpp
int start = nums[i];
```

然後一直看下一個數字是不是剛好大 1：

```cpp
nums[i] + 1 == nums[i + 1]
```

如果是，就代表還在同一段連續範圍裡，`i` 就繼續往右走。

等到不能繼續連續時，目前的 `nums[i]` 就是這一段的結尾：

```cpp
int end = nums[i];
```

如果：

```cpp
start == end
```

代表這段只有一個數字，所以答案放：

```cpp
"start"
```

如果：

```cpp
start != end
```

代表這段有好幾個連續數字，所以答案放：

```cpp
"start->end"
```

最後把每一段都處理完就可以了。

---

## 心得

這題其實不是很難，但是要小心題目要的是「區間」，不是每個數字都輸出。

一開始我可能會很直覺把每個數字都放進答案，  
但這樣就沒有做到 summary ranges。

這題讓我練習到用 while 迴圈找一段連續數字。  
只要記得先記起點，再往右找終點，就比較好想了。

還有 `(long long)nums[i] + 1` 是為了避免數字很大的時候加 1 爆掉，雖然平常測資不一定會遇到，但這樣寫比較安全。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
