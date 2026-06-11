#include <vector>
using namespace std;

class Solution {
    void combi(int n, int l, int r, string s, vector<string>& ans) {
        if (l == n && r == n) {
            ans.push_back(s);
            return;
        } 
        if (l < n)  combi(n, l + 1, r, s + "(", ans);
        if (r < l)  combi(n, l, r + 1, s + ")", ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        combi(n, 0, 0, "", ans);
        return ans;
    }
};