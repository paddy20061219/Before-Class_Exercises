# LeetCode 394 - Decode String

## 題目重點

這題會給一個被編碼過的字串，要把它還原。

編碼格式大概長這樣：

```txt
k[encoded_string]
```

意思是括號裡的字串要重複 `k` 次。

例如：

```txt
Input: "3[a]2[bc]"
Output: "aaabcbc"
```

因為：

```txt
3[a] = aaa
2[bc] = bcbc
```

所以合起來是：

```txt
aaabcbc
```

比較麻煩的是它可能會有巢狀括號，例如：

```txt
Input: "3[a2[c]]"
Output: "accaccacc"
```

---

## 錯誤程式碼

```cpp
#include <iostream>
#include <string>
using namespace std;

// LeetCode 394 - Decode String
// Wrong version: this code is intentionally incorrect.

class Solution {
public:
    string decodeString(string s) {
        string ans = "";

        // 錯誤想法：遇到數字就只重複下一個字元
        // 但題目中的括號裡可能是一整段字串，也可能有巢狀結構。
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int times = s[i] - '0';

                if (i + 2 < s.length()) {
                    char c = s[i + 2];

                    for (int j = 0; j < times; j++) {
                        ans += c;
                    }
                }
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                ans += s[i];
            }
        }

        return ans;
    }
};
```

---

## 錯誤原因

錯誤程式碼把題目想得太簡單，以為數字後面只會接一個字元。

例如：

```txt
Input: "3[a]"
```

它可能剛好可以做出接近的結果。

但是如果括號裡有多個字元，就會錯：

```txt
Input: "2[abc]"
Correct Output: "abcabc"
```

錯誤程式碼只會抓到 `a`，不會把整個 `"abc"` 重複。

另外，這題可能有巢狀括號：

```txt
Input: "3[a2[c]]"
Correct Output: "accaccacc"
```

錯誤程式碼沒有辦法記住外層和內層的狀態，所以這種情況一定會錯。

還有像 `12[a]` 這種多位數，錯誤程式碼也只會把 `1` 和 `2` 當成不同的數字處理。

---

## 正確程式碼

```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// LeetCode 394 - Decode String
// Correct version

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int number = 0;

        for (char c : s) {
            if (c >= '0' && c <= '9') {
                number = number * 10 + (c - '0');
            } else if (c == '[') {
                countStack.push(number);
                stringStack.push(current);

                number = 0;
                current = "";
            } else if (c == ']') {
                int times = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                string repeated = "";
                for (int i = 0; i < times; i++) {
                    repeated += current;
                }

                current = previous + repeated;
            } else {
                current += c;
            }
        }

        return current;
    }
};
```

---

## 解題想法

這題可以用 stack 來處理。

因為遇到 `[` 的時候，代表要開始處理一段新的字串。  
可是外面原本已經有一些字串和重複次數，所以要先把它們存起來。

我用兩個 stack：

```cpp
stack<int> countStack;
stack<string> stringStack;
```

`countStack` 用來存重複次數，`stringStack` 用來存進入括號前已經處理好的字串。

大致流程是：

1. 遇到數字時，把它累加成完整數字，因為可能是 `12`、`100` 這種多位數。
2. 遇到 `[` 時，把目前的數字和目前字串存進 stack。
3. 然後清空 `current`，開始處理括號裡的新字串。
4. 遇到 `]` 時，代表括號裡處理完了。
5. 從 stack 取出重複次數，把目前字串重複那麼多次。
6. 再接回之前存起來的字串。
7. 最後 `current` 就是解碼後的答案。

---

## 心得

這題一開始容易誤會成單純字串重複，但其實重點在括號可能會巢狀。

像 `3[a2[c]]` 這種測資，如果不用 stack，就很難記住目前是在第幾層括號裡。

這題讓我比較理解 stack 除了可以處理括號配對，也可以用來保存「進入下一層之前的狀態」。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
