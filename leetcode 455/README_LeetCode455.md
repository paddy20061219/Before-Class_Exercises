# LeetCode 455 - Assign Cookies

## 題目重點

這題會給兩個陣列：

```txt
g = 小孩的胃口
s = 餅乾的大小
```

`g[i]` 代表第 `i` 個小孩至少要吃多大的餅乾才會滿足。

`s[j]` 代表第 `j` 塊餅乾的大小。

規則是：

```txt
一個小孩最多只能拿一塊餅乾
一塊餅乾也只能給一個小孩
```

如果餅乾大小 >= 小孩胃口，這個小孩就會滿足。

題目要問：

```txt
最多可以讓幾個小孩滿足
```

例如：

```txt
g = [1,2,3]
s = [1,1]
```

只有兩塊大小為 1 的餅乾。  
只能滿足胃口是 1 的小孩，所以答案是：

```txt
1
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <vector>
using namespace std;

// LeetCode 455 - Assign Cookies
// wrong version: this code is intentionally very wrong.

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 蠢錯誤：直接回傳小孩數量
        // 題目要看餅乾夠不夠大，不是每個小孩一定都能滿足。
        return g.size();
    }
};
```

---

## 錯誤原因

這個錯誤版本直接回傳：

```cpp
g.size()
```

意思是它覺得所有小孩都可以被滿足。

可是這不一定。

例如：

```txt
g = [1,2,3]
s = [1,1]
```

有 3 個小孩，但是只有 2 塊餅乾，而且餅乾都很小。

錯誤程式碼會回傳：

```txt
3
```

但正確答案是：

```txt
1
```

因為只有胃口是 1 的小孩可以拿到大小 1 的餅乾。

所以這題不能只看小孩有幾個，還要看餅乾大小夠不夠。

---

## 正確程式碼

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 455 - Assign Cookies
// AC version

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child = 0;
        int cookie = 0;
        int count = 0;

        while(child < g.size() && cookie < s.size()){
            // 如果這塊餅乾可以滿足這個小孩
            if(s[cookie] >= g[child]){
                count++;
                child++;
                cookie++;
            } else {
                // 餅乾太小，就換下一塊比較大的餅乾
                cookie++;
            }
        }

        return count;
    }
};
```

---

## 解題想法

這題可以用貪心法。

先把小孩胃口排序：

```cpp
sort(g.begin(), g.end());
```

再把餅乾大小排序：

```cpp
sort(s.begin(), s.end());
```

排序後，就從胃口最小的小孩開始分餅乾。

想法是：

```txt
用最小可以滿足這個小孩的餅乾給他
```

這樣比較不會浪費大餅乾。

用兩個 index：

```cpp
child  看目前的小孩
cookie 看目前的餅乾
```

如果：

```cpp
s[cookie] >= g[child]
```

代表這塊餅乾可以滿足這個小孩。

所以：

```cpp
count++;
child++;
cookie++;
```

如果餅乾太小：

```cpp
s[cookie] < g[child]
```

代表這塊餅乾連目前胃口最小的小孩都滿足不了，  
那就只能換下一塊餅乾：

```cpp
cookie++;
```

最後 `count` 就是最多可以滿足的小孩數量。

---

## 心得

這題重點是不要亂把餅乾分給小孩。

先排序後，從胃口小的小孩開始處理會比較好想。  
如果小餅乾可以滿足小小孩，就先給他，不要浪費大餅乾。

我覺得這題是很基本的 greedy 題。  
主要要記得：餅乾太小時，不是換小孩，而是換下一塊餅乾。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
