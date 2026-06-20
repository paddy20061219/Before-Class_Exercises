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
