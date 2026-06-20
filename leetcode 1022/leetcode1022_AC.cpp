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
