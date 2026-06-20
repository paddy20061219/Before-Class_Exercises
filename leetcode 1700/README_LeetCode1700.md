# LeetCode 1700 - Number of Students Unable to Eat Lunch

## 題目重點

這題有兩個陣列：

```txt
students
sandwiches
```

`students[i]` 代表學生想吃的三明治類型：

```txt
0 = circular sandwich
1 = square sandwich
```

`sandwiches[i]` 代表三明治堆疊的順序，最前面的三明治會先被拿。

規則是：

1. 如果隊伍最前面的學生喜歡目前最上面的三明治，他就拿走三明治並離開。
2. 如果不喜歡，他就排到隊伍最後面。
3. 如果所有剩下的學生都不喜歡目前最上面的三明治，就沒有人可以再吃午餐。
4. 最後要回傳吃不到午餐的學生人數。

例如：

```txt
students = [1,1,0,0]
sandwiches = [0,1,0,1]
```

最後所有學生都可以吃到，所以答案是：

```txt
0
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1700 - Number of Students Unable to Eat Lunch
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int unable = 0;

        // 錯誤想法：直接比較同一個位置的學生和三明治
        // 但題目中的學生可以排到隊伍後面，不是只看原本 index。
        for (int i = 0; i < students.size(); i++) {
            if (students[i] != sandwiches[i]) {
                unable++;
            }
        }

        return unable;
    }
};
```

---

## 錯誤原因

錯誤程式碼把 `students[i]` 和 `sandwiches[i]` 直接拿來比較。

但是題目的流程不是照 index 一個一個配對。  
學生如果不喜歡目前的三明治，可以排到隊伍後面，所以學生順序會改變。

例如：

```txt
students = [1,1,0,0]
sandwiches = [0,1,0,1]
```

錯誤程式碼會比較：

```txt
students[0] = 1, sandwiches[0] = 0
students[1] = 1, sandwiches[1] = 1
students[2] = 0, sandwiches[2] = 0
students[3] = 0, sandwiches[3] = 1
```

所以它會以為有 2 個學生吃不到。

但其實學生可以排到後面，最後全部都吃得到，正確答案是：

```txt
0
```

所以不能直接用相同 index 判斷。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1700 - Number of Students Unable to Eat Lunch
// Correct version

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0, 0};

        // 統計喜歡圓形和方形三明治的學生人數
        for (int s : students) {
            count[s]++;
        }

        int remaining = students.size();

        // 依照三明治堆疊順序處理
        for (int sandwich : sandwiches) {
            if (count[sandwich] == 0) {
                return remaining;
            }

            count[sandwich]--;
            remaining--;
        }

        return 0;
    }
};
```

---

## 解題想法

這題其實不用真的模擬整個 queue。

因為學生只分成兩種喜好：

```txt
0 或 1
```

所以可以先統計：

```txt
喜歡 0 的學生有幾個
喜歡 1 的學生有幾個
```

接著照 `sandwiches` 的順序處理。

如果目前三明治是 `0`，但已經沒有學生喜歡 `0`，代表剩下的學生都不會拿這個三明治。  
這時候流程就卡住了，剩下的學生都吃不到。

如果還有人喜歡目前的三明治，就讓那一類學生人數減一，代表有一個學生拿到午餐了。

流程：

1. 統計學生喜歡 `0` 和 `1` 的人數。
2. 從第一個三明治開始看。
3. 如果沒有人喜歡目前三明治，直接回傳剩下學生數。
4. 如果有人喜歡，就扣掉一個人，繼續看下一個三明治。
5. 如果全部處理完，代表所有人都吃到，回傳 `0`。

---

## 心得

這題一開始看起來像是要用 queue 模擬學生一直排隊，但其實只要統計人數就可以。

因為學生不喜歡目前三明治時，只是換到後面，不會改變剩下學生喜歡哪一種三明治的數量。  
真正會讓流程停止的情況，是目前最上面的三明治沒有人想吃。

這題讓我學到，有些模擬題不一定要真的一步一步模擬，可以先觀察題目中真正重要的狀態是什麼。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
