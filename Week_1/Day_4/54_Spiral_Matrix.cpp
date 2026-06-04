#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> temp;
        int c = 1, i = 0, j = 0;
        int t = 0, b = n - 1, l = 0, r = m - 1;

        while (t <= b && l <= r){
            for (int i = l; i <= r; i++){
                temp.push_back(matrix[t][i]);
            }
            t++;

            for (int i = t; i <= b; i++){
                temp.push_back(matrix[i][r]);
            }
            r--;

            if (t <= b){
                for (int i = r; i >= l; i--){
                    temp.push_back(matrix[b][i]);
                }
                b--;
            }

            if (l <= r){
                for (int i = b; i >= t; i--){
                    temp.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        
        return temp;
    }
};