# LeetCode 110 - Balanced Binary Tree

## 題目重點

這題要判斷一棵 binary tree 是不是 height-balanced。

平衡二元樹的意思是：

```txt
對每一個節點來說，左子樹高度和右子樹高度的差不能超過 1
```

注意不是只檢查 root，而是樹裡每一個節點都要符合。

例如：

```txt
    3
   / \
  9  20
     / \
    15  7
```

這棵樹是 balanced，所以回傳：

```txt
true
```

如果某個節點的左右高度差超過 1，就要回傳 `false`。

---

## 錯誤程式碼

```cpp
#include <iostream>
using namespace std;

// LeetCode 110 - Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        // 錯誤想法：只檢查 root 左右子樹高度差
        // 但題目要求每一個節點都要符合平衡條件。
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return abs(leftHeight - rightHeight) <= 1;
    }

private:
    int height(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }
};
```

---

## 錯誤原因

錯誤程式碼只檢查 root 這個節點的左右子樹高度差。

但是題目要求的是：

```txt
每一個節點都要是平衡的
```

所以就算 root 的左右高度差沒有超過 1，下面的某個子樹還是可能不平衡。

例如有一棵樹，root 左右高度看起來差不多，可是左子樹裡面某一邊特別長。  
錯誤程式碼只看 root，就會誤判成 `true`。

正確做法應該要在算高度的同時，也檢查每一個節點是否平衡。

另外錯誤程式碼也少引入 `<cmath>` 和 `<algorithm>`，如果在比較嚴格的編譯環境中，`abs` 和 `max` 可能會出問題。

---

## 正確程式碼

```cpp
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// LeetCode 110 - Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) {
            return -1;
        }

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) {
            return -1;
        }

        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        return max(leftHeight, rightHeight) + 1;
    }
};
```

---

## 解題想法

這題可以用 DFS 從下面往上檢查。

每個節點要做兩件事：

1. 算出自己的高度。
2. 判斷左右子樹高度差有沒有超過 1。

我用 `checkHeight()` 來處理。  
如果某個子樹已經不平衡，就直接回傳 `-1`，表示不用再繼續正常算高度。

流程大概是：

1. 空節點高度是 `0`。
2. 先檢查左子樹高度。
3. 如果左子樹回傳 `-1`，代表已經不平衡，直接回傳 `-1`。
4. 再檢查右子樹高度。
5. 如果右子樹回傳 `-1`，也直接回傳 `-1`。
6. 如果左右高度差超過 1，回傳 `-1`。
7. 否則回傳目前節點高度。

最後 `isBalanced()` 只要判斷結果是不是 `-1` 就可以。

---

## 心得

這題我一開始容易只想到檢查 root 的左右高度，但那樣不夠，因為 balanced tree 是每一個節點都要符合。

比較好的做法是 DFS 一邊算高度，一邊檢查是否平衡。  
用 `-1` 當作不平衡的記號，寫起來比較簡潔，也不用對每個節點重複算很多次高度。

這題讓我更熟悉 binary tree 的遞迴，也提醒我題目如果說「每個節點」，就不能只看最上面的 root。

---

## AI 使用說明

本次訂正有使用 AI 工具協助整理錯誤原因、解題想法與 README 內容。  
程式碼與解題邏輯仍有依照題目需求進行理解與確認。
