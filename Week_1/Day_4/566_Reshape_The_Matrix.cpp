#include <vector>   
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if (r * c != m * n) return mat;

        vector<vector<int>> ans;
        vector<int> row;

        for (auto &v : mat) {
            for (int x : v) {
                row.push_back(x);

                if (row.size() == c) {
                    ans.push_back(row);
                    row.clear();
                }
            }
        }

        return ans;
    }
};