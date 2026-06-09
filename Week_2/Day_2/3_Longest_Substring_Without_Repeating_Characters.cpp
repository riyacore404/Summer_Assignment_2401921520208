#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return n;
        vector<int> mpp(256, -1);
        int c = 1, m = 0;

        int i = 0, j = 0;
        while (j < n) {
            if (mpp[s[j]] != -1) {
                i = max(mpp[s[j]] + 1, i);
            }
            mpp[s[j]] = j;
            c = j - i + 1;
            m = max(m, c);
            j++;
        }    
        return m;
    }
};