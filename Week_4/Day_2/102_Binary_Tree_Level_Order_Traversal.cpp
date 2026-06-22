#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            int n = nodes.size();
            vector<int> level;
            for (int i = 0; i < n; i++) {
                TreeNode* curr = nodes.front();
                nodes.pop();
                level.push_back(curr->val);
                if (curr->left) nodes.push(curr->left);
                if (curr->right) nodes.push(curr->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};