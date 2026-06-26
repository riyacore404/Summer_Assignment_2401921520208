#include <iostream>
#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& preorder, int preStart, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);

        int idx = pos[root->val];
        int leftSize = idx - inStart;

        root->left = build(preorder, preStart + 1, inorder, inStart, idx - 1);

        root->right = build(preorder, preStart + leftSize + 1, inorder, idx + 1,    inEnd);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        return build(preorder, 0, inorder, 0, inorder.size() - 1);
    }
};