#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();

            if (node == nullptr) ans += "null,";
            else {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            }
        }
        ans.pop_back();
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        vector<string> nodes;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* cur = q.front(); q.pop();

            // Left child
            if (nodes[i] != "null") {
                cur->left = new TreeNode(stoi(nodes[i]));
                q.push(cur->left);
            }
            i++;

            // Right child
            if (i < nodes.size() && nodes[i] != "null") {
                cur->right = new TreeNode(stoi(nodes[i]));
                q.push(cur->right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));