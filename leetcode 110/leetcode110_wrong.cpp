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
