#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int maxi = max(p->val, q->val);
        int mini = min(p->val, q->val);

        TreeNode* node = root;
        while (node) {
            if (maxi < node->val) node = node->left;
            else if (mini > node->val) node = node->right;
            else return node;
        }
        return node;
    }
};