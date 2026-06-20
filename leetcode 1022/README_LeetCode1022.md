# LeetCode 1022 - Sum of Root To Leaf Binary Numbers

## 題目重點

這題給一棵 binary tree，每個節點的值只會是 `0` 或 `1`。

從 root 到每一個 leaf，都可以形成一個二進位數字。  
題目要把所有 root-to-leaf 路徑形成的二進位數字加起來。

例如一條路徑是：

```txt
1 -> 0 -> 1
```

代表二進位：

```txt
101
```

換成十進位就是：

```txt
5
```

如果樹裡有多條 root 到 leaf 的路徑，就要把每條路徑算出的數字加總。

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 1022 - Sum of Root To Leaf Binary Numbers
// Wrong version: this code is intentionally incorrect.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        // 錯誤想法：只把所有節點的值加起來
        // 但題目要求的是每條 root 到 leaf 路徑形成的二進位數字總和。
        if (root == nullptr) {
            return 0;
        }

        return root->val + sumRootToLeaf(root->left) + sumRootToLeaf(root->right);
    }
};
```

---

## 錯誤原因

錯誤程式碼只是把所有節點的 `val` 加起來。

但是這題不是要算節點值總和，而是要看每一條從 root 到 leaf 的路徑。

例如路徑：

```txt
1 -> 0 -> 1
```

不是算：

```txt
1 + 0 + 1 = 2
```

而是要把它當成二進位：

```txt
101
```

也就是十進位的：

```txt
5
```

所以單純把節點值加起來會完全錯掉。

另外，只有走到 leaf 的時候，才代表形成了一個完整的二進位數字。中間節點不能直接當成答案加總。

---

## 正確程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 1022 - Sum of Root To Leaf Binary Numbers
// Correct version

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current) {
        if (node == nullptr) {
            return 0;
        }

        // 二進位往下一層時，相當於原本數字乘以 2 再加目前節點值
        current = current * 2 + node->val;

        // leaf node：代表一條完整路徑結束
        if (node->left == nullptr && node->right == nullptr) {
            return current;
        }

        return dfs(node->left, current) + dfs(node->right, current);
    }
};
```

---

## 解題想法

這題可以用 DFS。

走樹的時候，要一路記錄目前路徑形成的二進位數字。

假設目前累積的數字是 `current`，往下一層走到新的節點時，新的值就是：

```cpp
current = current * 2 + node->val;
```

因為二進位每往右補一位，就等於原本數字乘以 2，再加上新的位元。

例如：

```txt
1 -> 0 -> 1
```

計算過程：

```txt
0 * 2 + 1 = 1
1 * 2 + 0 = 2
2 * 2 + 1 = 5
```

走到 leaf 時，代表這條路徑已經完整，就回傳目前的 `current`。  
如果不是 leaf，就繼續往左子樹和右子樹 DFS，最後把左右結果加起來。

---

## 心得

這題一開始容易看成樹的節點總和，但其實重點是「路徑」和「二進位轉十進位」。

我覺得比較重要的是理解這行：

```cpp
current = current * 2 + node->val;
```

它就是在把目前節點接到二進位數字後面。  
這題讓我練習到 DFS，也讓我知道走樹的時候可以把目前累積的狀態一路往下傳。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
