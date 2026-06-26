#include <iostream>
using namespace std;

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        q.push(root);

        while (!q.empty()) {
            TreeNode* root1 = q.front(); q.pop();
            TreeNode* root2 = q.front(); q.pop();

            if (!root1 && !root2) continue;
            if (!root1 || !root2) return false;
            if (root1->val != root2->val) return false;

            q.push(root1->left); q.push(root2->right);
            q.push(root1->right); q.push(root2->left);
        }

        return true;
    }
};