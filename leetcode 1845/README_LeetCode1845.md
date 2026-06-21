# LeetCode 1845 - Seat Reservation Manager

## 題目重點

這題要設計一個座位管理系統。

一開始有 `n` 個座位，編號是：

```txt
1, 2, 3, ..., n
```

題目要實作兩個功能：

```cpp
reserve()
unreserve(seatNumber)
```

規則是：

1. `reserve()` 要回傳目前還沒被預約的最小座位編號。
2. 回傳後，這個座位就變成已經被預約。
3. `unreserve(seatNumber)` 會把某個座位取消預約，讓它之後可以再被預約。
4. 每次都要拿最小的可用座位。

例如：

```txt
SeatManager seatManager = new SeatManager(5);

reserve() -> 1
reserve() -> 2
unreserve(2)
reserve() -> 2
reserve() -> 3
```

因為取消 2 之後，2 又變成目前最小的可用座位。

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 1845 - Seat Reservation Manager
// wrong version: this code is intentionally very wrong.

class SeatManager {
public:
    SeatManager(int n) {
        // 蠢錯誤：完全沒有記錄有哪些座位可以用
    }

    int reserve() {
        // 蠢錯誤：每次都回傳 1
        // 但同一個座位不能一直被重複預約。
        return 1;
    }

    void unreserve(int seatNumber) {
        // 蠢錯誤：取消預約也什麼都不做
    }
};
```

---

## 錯誤原因

這個錯誤版本完全沒有管理座位狀態。

`reserve()` 每次都直接回傳：

```cpp
1
```

但如果座位 1 已經被預約了，就不能再回傳 1。

例如：

```txt
SeatManager(3)
reserve()
reserve()
```

正確應該是：

```txt
1
2
```

但是錯誤程式碼會變成：

```txt
1
1
```

這樣同一個座位被預約兩次，明顯不合理。

另外 `unreserve(seatNumber)` 也什麼都沒做。  
所以就算某個座位被取消預約，程式也不會真的把它加回可用座位裡。

這題一定要記錄哪些座位目前可以用，不能直接亂回傳固定數字。

---

## 正確程式碼

```cpp
#include <iostream>
#include <set>
using namespace std;

// LeetCode 1845 - Seat Reservation Manager
// AC version

class SeatManager {
private:
    set<int> availableSeats;

public:
    SeatManager(int n) {
        for(int i = 1; i <= n; i++){
            availableSeats.insert(i);
        }
    }

    int reserve() {
        int seat = *availableSeats.begin();

        availableSeats.erase(seat);

        return seat;
    }

    void unreserve(int seatNumber) {
        availableSeats.insert(seatNumber);
    }
};
```

---

## 解題想法

這題可以用 `set`。

因為題目每次都要拿：

```txt
目前最小的可用座位
```

`set` 會自動把數字由小到大排好，所以最小值就在：

```cpp
*availableSeats.begin()
```

一開始要把 `1` 到 `n` 的座位都放進 set：

```cpp
for(int i = 1; i <= n; i++){
    availableSeats.insert(i);
}
```

當呼叫 `reserve()` 時：

1. 拿出 set 裡最小的座位。
2. 把這個座位從 set 裡刪掉，表示已經被預約。
3. 回傳這個座位號碼。

當呼叫 `unreserve(seatNumber)` 時：

1. 把 `seatNumber` 放回 set。
2. 代表這個座位又可以被預約了。

---

## 心得

這題其實是在練怎麼管理「目前可以用的最小編號」。

如果每次自己用陣列找最小可用座位，會比較麻煩。  
用 `set` 就簡單很多，因為它會自動排序，而且可以很快插入和刪除。

我覺得這題最重要的是不要忘記：  
`reserve()` 之後要把座位刪掉，`unreserve()` 之後要把座位加回來。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
