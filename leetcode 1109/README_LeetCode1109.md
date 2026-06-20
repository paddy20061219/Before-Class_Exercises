# LeetCode 1109 - Corporate Flight Bookings

## 題目重點

這題給一個航班訂位紀錄陣列 `bookings`，以及航班數量 `n`。

每筆訂位資料格式是：

```txt
[first, last, seats]
```

意思是從第 `first` 班航班到第 `last` 班航班，每一班都被訂了 `seats` 個座位。

題目要求回傳一個長度為 `n` 的陣列，其中第 `i` 個位置代表第 `i + 1` 班航班總共被訂了多少座位。

例如：

```txt
Input:
bookings = [[1,2,10],[2,3,20],[2,5,25]]
n = 5

Output:
[10,55,45,25,25]
```

解釋：

```txt
第 1 班：10
第 2 班：10 + 20 + 25 = 55
第 3 班：20 + 25 = 45
第 4 班：25
第 5 班：25
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1109 - Corporate Flight Bookings
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        // 錯誤想法：只把座位數加到起始航班
        // 但題目要求 first 到 last 之間的每一班都要加。
        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int seats = bookings[i][2];

            ans[first - 1] += seats;
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼只把座位數加到 `first` 那一班航班。

但是題目規定每筆訂位 `[first, last, seats]` 代表：

```txt
first 到 last 之間的每一班航班都要加 seats
```

例如：

```txt
bookings = [[1,2,10]]
n = 3
```

正確結果應該是：

```txt
[10,10,0]
```

因為第 1 班和第 2 班都被訂了 10 個座位。

錯誤程式碼只會輸出：

```txt
[10,0,0]
```

所以它漏掉了區間內後面的航班。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1109 - Corporate Flight Bookings
// Correct version

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);

        // 使用差分陣列處理區間加法
        for (int i = 0; i < bookings.size(); i++) {
            int first = bookings[i][0];
            int last = bookings[i][1];
            int seats = bookings[i][2];

            diff[first - 1] += seats;

            if (last < n) {
                diff[last] -= seats;
            }
        }

        vector<int> ans(n, 0);
        ans[0] = diff[0];

        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] + diff[i];
        }

        return ans;
    }
};
```

---

## 解題想法

這題是典型的區間加法問題，可以用差分陣列解。

如果每筆訂位都用迴圈把 `first` 到 `last` 全部加一次，雖然直覺，但資料量大時會太慢。

差分陣列的做法是：

```txt
在區間開始位置加 seats
在區間結束後一格減 seats
最後做前綴和還原答案
```

對於一筆訂位：

```txt
[first, last, seats]
```

因為航班編號從 1 開始，但陣列 index 從 0 開始，所以：

```cpp
diff[first - 1] += seats;
diff[last] -= seats;
```

其中 `diff[last] -= seats` 只有在 `last < n` 時才需要做，因為如果 `last` 已經是最後一班，就沒有下一格可以扣掉。

最後把 `diff` 做前綴和，就可以得到每一班航班的總訂位數。

---

## 心得

這題如果用暴力法，對每筆訂位都從 `first` 加到 `last`，雖然容易理解，但效率不好。

差分陣列可以把每次區間加法變成只修改兩個位置，最後再用一次前綴和算出答案。  
這題讓我學到，遇到大量「區間加總」或「範圍更新」的題目時，可以優先想到差分陣列。
