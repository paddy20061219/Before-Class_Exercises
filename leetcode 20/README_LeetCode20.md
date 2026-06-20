# LeetCode 20 - Valid Parentheses

## 題目重點

這題要判斷一個只包含括號的字串是不是合法。

括號包含三種：

```txt
()
[]
{}
```

合法的意思是：

1. 左括號要有對應的右括號。
2. 括號的順序要正確。
3. 不同種類的括號不能交錯配對。
4. 最後不能剩下沒有配對的左括號。

例如：

```txt
Input: "()[]{}"
Output: true
```

因為每一組括號都有正確配對。

但：

```txt
Input: "([)]"
Output: false
```

雖然括號數量看起來都有對到，可是順序是錯的。

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

// LeetCode 20 - Valid Parentheses
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    bool isValid(string s) {
        int round = 0;
        int square = 0;
        int curly = 0;

        // 錯誤想法：只計算每種括號數量是否相同
        // 但沒有檢查括號的順序和配對位置。
        for (char c : s) {
            if (c == '(') round++;
            else if (c == ')') round--;
            else if (c == '[') square++;
            else if (c == ']') square--;
            else if (c == '{') curly++;
            else if (c == '}') curly--;
        }

        return round == 0 && square == 0 && curly == 0;
    }
};
```

---

## 錯誤原因

錯誤程式碼只看每種括號的數量有沒有抵消掉。

但是這題不是只看數量，還要看括號的配對順序。

例如：

```txt
Input: "([)]"
```

錯誤程式碼會覺得：

```txt
( 和 ) 數量相同
[ 和 ] 數量相同
```

所以回傳：

```txt
true
```

但實際上正確答案是：

```txt
false
```

因為 `[` 還沒被關掉時，先出現了 `)`，所以括號順序已經錯了。

另外像這種：

```txt
Input: ")("
```

數量也可以抵消成 0，但一開始就出現右括號，這也不是合法括號。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// LeetCode 20 - Valid Parentheses
// Correct version

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }

                char top = st.top();
                st.pop();

                if (c == ')' && top != '(') {
                    return false;
                }

                if (c == ']' && top != '[') {
                    return false;
                }

                if (c == '}' && top != '{') {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
```

---

## 解題想法

這題可以用 stack。

因為括號配對有「後出現的左括號，要先被關掉」的特性，剛好符合 stack 的後進先出。

做法是：

1. 遇到左括號 `(`、`[`、`{`，就放進 stack。
2. 遇到右括號時，先檢查 stack 是否為空。
3. 如果 stack 是空的，代表沒有左括號可以配對，直接回傳 `false`。
4. 如果 stack 不空，就拿出最上面的左括號。
5. 檢查右括號和這個左括號是不是同一組。
6. 如果不是同一組，就回傳 `false`。
7. 全部檢查完後，如果 stack 是空的，代表全部都有配對成功。

---

## 心得

這題一開始很容易想成只要左右括號數量一樣就好。

但其實括號題最重要的是順序。像 `([)]` 這種例子，數量完全沒問題，可是配對順序錯了。

用 stack 會比較直覺，因為最近出現的左括號一定要最先被關起來。這題也讓我更熟悉 stack 適合處理配對問題。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
