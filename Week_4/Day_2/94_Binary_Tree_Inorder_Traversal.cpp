#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        stack<TreeNode*> nodes;
        TreeNode* node = root;

        while(1) {
            if (node) {
                nodes.push(node);
                node = node->left;
            }
            else {
                if (nodes.empty()) break;
                node = nodes.top();
                nodes.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};